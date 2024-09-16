#ifndef U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#define U05_ARBOL_ARBOL_ARBOLBINARIO_H_

#include "NodoArbol.h"

template <class T>
class ArbolBinario
{
protected:
  NodoArbol<T> *root;

public:
  ArbolBinario();

  void put(T data);

  T search(T data);

  void remove(T data);

  void preorder();

  void inorder();

  void postorder();

  ~ArbolBinario();

  bool esVacio();

  void print();

private:
  T search(T data, NodoArbol<T> *r);
  NodoArbol<T> *put(T data, NodoArbol<T> *r);
  NodoArbol<T> *remove(T data, NodoArbol<T> *r);
  NodoArbol<T> *findMaxAndRemove(NodoArbol<T> *r, bool *found);
  void preorder(NodoArbol<T> *r);
  void inorder(NodoArbol<T> *r);
  void postorder(NodoArbol<T> *r);
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T>
ArbolBinario<T>::ArbolBinario() { root = nullptr; }

/**
 * Destructor del Arbol
 */
template <class T>
ArbolBinario<T>::~ArbolBinario() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T>
T ArbolBinario<T>::search(T data)
{
  return search(data, root);
}

template <class T>
T ArbolBinario<T>::search(T data, NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    throw 404;
  }

  if (r->getData() == data)
  {
    return r->getData();
  }

  if (r->getData() > data)
  {
    return search(data, r->getLeft());
  }
  else
  {
    return search(data, r->getRight());
  }
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T>
void ArbolBinario<T>::put(T data) { root = put(data, root); }

template <class T>
NodoArbol<T> *ArbolBinario<T>::put(T data, NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return new NodoArbol<T>(data);
  }

  if (r->getData() == data)
  {
    throw 200;
  }

  if (r->getData() > data)
  {
    r->setLeft(put(data, r->getLeft()));
  }
  else
  {
    r->setRight(put(data, r->getRight()));
  }

  return r;
}

/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template <class T>
void ArbolBinario<T>::remove(T data)
{
  root = remove(data, root);
}
//
//template <class T>
//NodoArbol<T> *ArbolBinario<T>::remove(T data, NodoArbol<T> *r)
//{
//  NodoArbol<T> *aux;
//
//  if (r == nullptr)
//  {
//    throw 404;
//  }
//
//  if (r->getData() == data)
//  {
//
//    if (r->getLeft() == nullptr && r->getRight() == nullptr)
//    {
//      delete r;
//      return nullptr;
//    }
//    else if (r->getLeft() != nullptr && r->getRight() == nullptr)
//    {
//      aux = r->getLeft();
//      delete r;
//      return aux;
//    }
//    else if (r->getLeft() == nullptr && r->getRight() != nullptr)
//    {
//      aux = r->getRight();
//      delete r;
//      return aux;
//    }
//    else if (r->getLeft() != nullptr && r->getRight() != nullptr)
//    {
//
//      if (r->getLeft()->getRight() != nullptr)
//      {
//        // Aca tenemos que buscar el valor maximo
//        bool found;
//        aux = findMaxAndRemove(r->getLeft(), &found);
//        aux->setRight(r->getRight());
//        aux->setLeft(r->getLeft());
//      }
//      else
//      {
//        aux = r->getLeft();
//        r->getLeft()->setRight(r->getRight());
//      }
//      delete r;
//      return aux;
//    }
//  }
//  else if (r->getData() > data)
//  {
//    r->setLeft(remove(data, r->getLeft()));
//  }
//  else
//  {
//    r->setRight(remove(data, r->getRight()));
//  }
//
//  return r;
//}
template <class T>
NodoArbol<T> *ArbolBinario<T>::remove(T data, NodoArbol<T> *r)
{
    if (r == nullptr)
    {
        throw 404;  // Si el nodo es nulo, lanzamos excepción de "no encontrado"
    }

    if (data < r->getData())
    {
        // Si el valor a eliminar es menor, buscamos en el subárbol izquierdo
        r->setLeft(remove(data, r->getLeft()));
    }
    else if (data > r->getData())
    {
        // Si el valor a eliminar es mayor, buscamos en el subárbol derecho
        r->setRight(remove(data, r->getRight()));
    }
    else
    {
        // Si encontramos el nodo a eliminar
        if (r->getLeft() == nullptr && r->getRight() == nullptr)
        {
            // Caso 1: El nodo es una hoja (sin hijos)
            delete r;
            return nullptr;
        }
        else if (r->getLeft() == nullptr)
        {
            // Caso 2: El nodo tiene solo hijo derecho
            NodoArbol<T> *temp = r->getRight();
            delete r;
            return temp;
        }
        else if (r->getRight() == nullptr)
        {
            // Caso 3: El nodo tiene solo hijo izquierdo
            NodoArbol<T> *temp = r->getLeft();
            delete r;
            return temp;
        }
        else
        {
            // Caso 4: El nodo tiene dos hijos
            NodoArbol<T> *temp = findMaxAndRemove(r->getLeft(), nullptr);  // Buscamos el máximo en el subárbol izquierdo
            r->setData(temp->getData());  // Reemplazamos los datos del nodo actual
            r->setLeft(remove(temp->getData(), r->getLeft()));  // Eliminamos el nodo que contenía el mayor valor
        }
    }
    return r;
}
//
//template <class T>
//NodoArbol<T> *ArbolBinario<T>::findMaxAndRemove(NodoArbol<T> *r, bool *found)
//{
//  NodoArbol<T> ret;
//  *found = false;
//
//  if (r->getRight() == nullptr)
//  {
//    *found = true;
//    return r;
//  }
//
//  ret = findMaxAndRemove(r->getRight(), found);
//  if (*found)
//  {
//    r->setRight(ret);
//    *found = false;
//  }
//
//  return ret;
//}
template <class T>
NodoArbol<T> *ArbolBinario<T>::findMaxAndRemove(NodoArbol<T> *r, bool *found)
{
    if (r->getRight() == nullptr)
    {
        // Si no tiene subárbol derecho, este es el máximo
        NodoArbol<T> *maxNode = r;
        r = r->getLeft();  // Actualizamos el puntero para el padre del nodo máximo
        return maxNode;
    }
    r->setRight(findMaxAndRemove(r->getRight(), found));
    return r;
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T>
bool ArbolBinario<T>::esVacio() { return root == nullptr; }

/**
 * Recorre un árbol en preorden
 */
template <class T>
void ArbolBinario<T>::preorder()
{
  preorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::preorder(NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  std::cout << r->getData() << " ";
  preorder(r->getLeft());
  preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template <class T>
void ArbolBinario<T>::inorder()
{
  inorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::inorder(NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  inorder(r->getLeft());
  std::cout << r->getData() << " ";
  inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template <class T>
void ArbolBinario<T>::postorder()
{
  postorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::postorder(NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  postorder(r->getLeft());
  postorder(r->getRight());
  std::cout << r->getData() << " ";
}

/**
 * Muestra un árbol por consola
 */
template <class T>
void ArbolBinario<T>::print()
{
  if (root != NULL)
    root->print(false, "");
}

#endif // U05_ARBOL_ARBOL_ARBOLBINARIO_H_

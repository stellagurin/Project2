#include<iostream>
#include<fstream>
#include<string>
#include "SortedList.h"

using namespace std;

template <class ItemType>
SortedList<ItemType>::SortedList()
// Constructor
{
    Length = 0;
    ListData = NULL;
    current = NULL;
}

template <class ItemType>
SortedList<ItemType>::~SortedList()
// Destructor
{
    makeEmpty();
}

template <class ItemType>
void SortedList<ItemType>::makeEmpty()
{
    Node<ItemType>* tempPtr;
    while (ListData != NULL) {
        tempPtr = ListData;
        ListData = ListData->next;
        delete tempPtr;
    }
    Length = 0;
}

template <class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
    if (Length == 0) {
        return true;
    }
    return false;
}

template <class ItemType>
bool SortedList<ItemType>::isFull() const
{
    try {
        Node<ItemType>* testPtr = new Node<ItemType>;
        delete testPtr;
    } catch (bad_alloc&) {
        return true;
    }
    return false;
}

template <class ItemType>
void SortedList<ItemType>::putItem(ItemType newItem)
{
    Node<ItemType>* pred = NULL;
    if (isFull()) {
        throw FullList();
    } else {
        Node<ItemType>* newNode = new Node<ItemType>;
        newNode->info = newItem;
        Node<ItemType>* loc;

        Node<ItemType>* prevLoc;
        bool moreToSearch;

        loc = ListData;
        prevLoc = NULL;

        moreToSearch = (loc != NULL);

        while (moreToSearch) {


            if(loc->info == newItem){
                throw DuplicateItem();
            }

            if(loc->info < newItem){
                prevLoc = loc;
                loc = loc->next;
                moreToSearch = (loc != NULL);
            } //if

            else {
                moreToSearch=false;
            }

        } //while

        if (prevLoc == NULL) {
            newNode->next = ListData;
            ListData = newNode;
        } //if

        else {
            newNode->next = loc;
            prevLoc->next = newNode;
        }

        Length++;
    }

}

template <class ItemType>
void SortedList<ItemType>::deleteItem(ItemType item)
{
    if (isFull()) {
        throw FullList();
    } else if (isEmpty()) {
        throw EmptyList();
    } else {
        Node<ItemType>* loc;
        Node<ItemType>* prevLoc;
        bool moreToSearch;
        bool found = false;

        loc = ListData;
        prevLoc = NULL;

        moreToSearch = (loc != NULL);

        while(moreToSearch){
            if (loc->info < item){

                prevLoc = loc;
                loc = loc->next;
                moreToSearch = (loc != NULL);
            } //if

            else if (loc->info == item) {
                moreToSearch = false;
                found=true;
            } else {
                moreToSearch = false;
                found=false;
            }

        } //while

        if(ListData->info == item){
            ListData = ListData->next;
            delete loc;
            Length--;
        } //if

        else if (found){
            prevLoc->next = loc->next;
            delete loc;
            Length--;
        } //if

        else {
            throw DeletingMissingItem();

        }
    }
}

template <class ItemType>
int SortedList<ItemType>::getLength() const
{
    return Length;
}

template <class ItemType>
ItemType SortedList<ItemType>::getAt(int i)
{
    Node<ItemType>* tempPtr = ListData;
    if (0 < i && i <= Length) {
        for (int j = 1; j < i; j++) {
            tempPtr = tempPtr->next;
        }
    } else {
        throw OutOfBound();
    }
    return tempPtr->info;
}

template <class ItemType>
void SortedList<ItemType>::merge(SortedList& otherList)
{
    if (Length == 0) {
        ListData = otherList.ListData;
        otherList.makeEmpty();
    }
}

template <class ItemType>
void SortedList<ItemType>::printList(ofstream& outFile)
{
    Node<ItemType>* loc = ListData;

    outFile << "List Items : ";
    for(int i = 0; i < Length; i++){
        outFile << loc->info << "->";
        loc = loc->next;
    } //for
    outFile << "NULL";
    outFile << endl;
    outFile << endl;
}

template <class ItemType>
bool SortedList<ItemType>::findItem(ItemType item, Node<ItemType>*& predecessor)
{
    return true;
}

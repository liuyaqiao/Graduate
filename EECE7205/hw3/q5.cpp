//
// Created by Yaqiao on 2018/2/14.
//

void Heap::HeapInsert(Object *object)
{
    int index;
    this->Insert(this->GetLength(),object);
    index = this->GetLength()-1;
    while (!(this->Get(index)->Compare(this->Get(Parent(index))))     &&  (index!=0))
    {
        Exchange(index,Parent(index));
        index = Parent(index);

    }

}
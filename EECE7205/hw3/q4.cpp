//
// Created by Yaqiao on 2018/2/14.
//

Object *Heap::ExtractMax()
{
    Object *object;
    BulidMaxHeap();
    object = this->Get(0);
    this->Delete(0);
    BulidMaxHeap();
    return object;
}
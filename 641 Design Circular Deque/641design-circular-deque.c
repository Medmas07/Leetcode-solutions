


typedef struct {
    int*data;
    int head;
    int tail;
    int size;
    int max_size;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque*d=malloc(sizeof(MyCircularDeque));
    d->data=malloc(sizeof(int)*k);
    d->head = 0;
    d->tail = 0;
    d->max_size = k;
    d->size = 0;

    return d;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if((obj->size)+1>obj->max_size)
        return 0;
    else
    {
        for(int i=(obj->size);i>0;i--)
        {
            obj->data[i]=obj->data[i-1];
        }
        (obj->size)++;
        obj->data[0]=value;
        return 1;
    }
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if((obj->size)+1>obj->max_size)
        return 0;
    else
    {
        obj->data[obj->size]=value;
        (obj->size)++;
        return 1;
    }
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj== NULL || obj->size==0)
        return 0;
    for(int j=1;j<obj->size;j++)
    {
        obj->data[j-1]=obj->data[j];
    }
    (obj->size)--;
    return 1;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(obj==NULL || obj->size == 0)
        return 0;
    (obj->size)--;
    (obj->tail)--;
    return 1;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(obj==NULL ||  obj->size==0)
        return -1;
    else
        return obj->data[0];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(obj==NULL ||  obj->size==0)
        return -1;
    else
    {
        for(int i=0;i<obj->size;i++)
            printf("obj->size[%d]=%d \n",i,obj->data[i]);
        return obj->data[(obj->size) -1];  
    }
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if(obj==NULL ||  obj->size==0)
        return 1;
    else 
        return 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if(obj==NULL ||  obj->size==0 || obj->size!=obj->max_size)
        return 0;
    else
        return 1;
    
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
#include <nan.h>
#include "asyncAdd.h"

// using namespace Nan;
using namespace v8;

AsyncAdd::AsyncAdd(int a, int b, Nan::Callback* callback) : Nan::AsyncWorker(callback){
    this->a = a;
    this->b = b;
}

AsyncAdd::~AsyncAdd(){}

void AsyncAdd::Execute(){
    // 执行函数
    this->sum = this->a  + this->b;
}

// 将计算结构通过回调函数返回
void AsyncAdd::HandleOKCallback(){
    Nan::AsyncResource* as = new Nan::AsyncResource("asyncAdd");
    // 回调函数的参数，第一个为错误参数默认为空，Null()/Undefined()
    Local<Value> argv[2] = {
        Nan::Undefined(),
        Nan::New(this->sum)
    };
    callback->Call(2 , argv, as);
}
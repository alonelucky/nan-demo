#include <nan.h>
#include <iostream>
#include "method/asyncAdd.h"

using namespace std;
using namespace v8;

// 异步加法
NAN_METHOD(asyncAdd){
    int len = info.Length();
    // 参数校验
    if(len < 3){
        Nan::ThrowTypeError("函数必须有三个参数");
    }
    // 整理参数
    int a = Nan::To<int>(info[0]).FromJust();
    int b = Nan::To<int>(info[1]).FromJust();
    Nan::Callback* callback = new Nan::Callback(info[2].As<Function>());
    // 将定义的队列类实例化对象加入事件队列
    Nan::AsyncQueueWorker(new AsyncAdd(a, b, callback));
}

// 同步加法，涉及基础数据类型转换
NAN_METHOD(syncAdd){
    int len = info.Length();
    if(len<1){
        // 如果参数长度少于一个，抛出类型错误
        Nan::ThrowError("参数至少一个");
        return;
    }

    double a = Nan::To<double>(info[0]).FromJust();
    double b = Nan::To<double>(info[1]).FromJust();
    double sum = a + b;
    cout << a << b << sum << endl;
    info.GetReturnValue().Set(Nan::New(sum));
}

NAN_MODULE_INIT(Init){
    /**
     * 创建方法
     * */
    Nan::Export(target,"syncAdd",syncAdd);
    Nan::Export(target,"asyncAdd",asyncAdd);
    /**
     * Create a property with base type
     * */
    Nan::Set(target,Nan::New("string").ToLocalChecked(),Nan::New("Hello my addon string").ToLocalChecked());
    Nan::Set(target,Nan::New("number").ToLocalChecked(),Nan::New(123));
    Nan::Set(target,Nan::New("bool").ToLocalChecked(),Nan::New(true));
}

NODE_MODULE(addon,Init);
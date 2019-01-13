#include <nan.h>

using namespace v8;

class AsyncAdd : public Nan::AsyncWorker {
    private:
        int a, b, sum;
    public:
        AsyncAdd(int a, int b, Nan::Callback* callback);
        ~AsyncAdd();
        void Execute();
        void HandleOKCallback();
};
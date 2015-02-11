#include <iostream>
 
extern "C"
{
#include <SDL/SDL_timer.h>
#include <SDL/SDL.h>
}
using namespace std;
 
 
class Object
{
    public:
        static void publicStaticFunction()
        {
            cout<<"i am a public static function"<<endl;
            cout<<"i will call privateStaticFunction()"<<endl;
            privateStaticFunction();
 
        }
 
    private:
        static void privateStaticFunction()
        {
            cout<<"i am a private static function"<<endl;
        }
 
    public:
        /*static*/ void scheduleRefresh(int delay)
        //can't be static because use "this"
        {
            SDL_RemoveTimer(timerID);
            timerID=SDL_AddTimer(delay,refreshWrapper,this);
            cout<<"after "<<delay<<" will call refreshWrapper"<<endl;
        }
        private:
        static unsigned int refreshWrapper(unsigned int interval,void* me)
        //must be static!
        {
            cout<<"refreshWrapper call!"<<endl;
            static_cast<Object*>(me)->refresh();
            return 0;
        }
        //如果不是static编译的时候会报错
        //error: argument of type ‘unsigned int (Object::)(unsigned int, void*)’ does not match ‘Uint32 (*)(Uint32, void*)’
        //可以看到它可以调用私有的refresh
        void refresh()
        {
            printf("my address is %p \r\n",this);
        }
        private:
        SDL_TimerID timerID;
 
};
 
int main()
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER);
    Object::publicStaticFunction();
    //Object::privateStaticFunction();
    Object o1;
    o1.scheduleRefresh(2000);
    Object o2;
    o2.scheduleRefresh(3000);
    return 0;
}

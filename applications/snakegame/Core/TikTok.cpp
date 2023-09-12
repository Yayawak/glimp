// #include <functional>
// #include <iostream>
// #include <iterator>
// #include <pthread.h>
// #include <unistd.h>
// #include <vector>
// // #pragma startup 

// // template <class T>
// // class Observer
// // {
// // public:
// //     Observer() {}
// //     virtual ~Observer() {}
// //     virtual void update(T *subject) = 0;
// // };


// // template <class T>
// // class Subject
// // {
// // private:
// //     std::vector<Observer<T> *> observers;
// // public:
// //     Subject() {};
// //     virtual ~Subject() {}
// //     void attach(Observer<T> &observer)
// //     {
// //         observers.push_back(&observer);
// //     }
// //     void notify()
// //     {
// //         // std::vector<Observer<T> *>::it = observers.begin();
// //         auto it = observers.begin();
// //         // vector<_Tp, _Allocator>::iterator
// //         while (it != observers.end()) 
// //         {
// //             (*it)->update(static_cast<T *>(this));
// //         }
// //     }
// // };



// // class TikTok : public Subject<TikTok>
// class TikTok
// {
// private:
//     // std::vector<std::function<void()> > registeredFunctions;
//     pthread_t ptid;
//     // static bool isEnd = false;
//     static bool isEnd;

//     static std::vector<void (*)()> registeredFunctions;

//     static void tick()
//     {
//         for (auto& function : registeredFunctions)
//         {
//             function();
//         }
//         // notify();
//     }

//     static void *infinityLoopUntilSignal(void *args)
//     {
//         pthread_detach(pthread_self());
//         while (!isEnd)
//         {
//             tick();
//             sleep(1);
//         }
//         pthread_exit(NULL);
//     }

// public:
//     TikTok()
//     {
//         pthread_create(&ptid, NULL, &TikTok::infinityLoopUntilSignal, this);
//         // pthread_create(&ptid,
//         //     NULL,
//         //     static_cast<void *(*)(void *)>(&TikTok::infinityLoopUntilSignal),
//         //     // static_cast<void *(*)(void *)>(infinityLoopUntilSignal),
//         //     // &TikTok::infinityLoopUntilSignal,
//         //     this);
//         // outterInitor();
//         // infinityLoopUntilSignal(NULL);
//     }



//     void registerFn(void (*f)(void))
//     {
//         registeredFunctions.push_back(f);        
//     }

//     void endInfinityLoop()
//     {
//         isEnd = true;
//         pthread_join(ptid, NULL);
//         #ifdef ForTest
//         std::cout << "End of infinite loop in TikTok\n";
//         #endif
//     }
// };


// // static void outterInitor()
// // {
// //     pthread_create(&ptid, NULL, &TikTok::infinityLoopUntilSignal, tk);

// // }
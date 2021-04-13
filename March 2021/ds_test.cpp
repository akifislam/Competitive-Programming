
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<stdio.h>


using namespace std;

int main()
{
    long int  i, n, t, x, stack_flag, queue_flag, prio_queue_flag;

    while(scanf("%ld",&n)==1)
    {
        stack<long int> mystack;
        queue<long int> myqueue;
        priority_queue<long int> mypq;

        stack_flag=0;
        queue_flag=0;
        prio_queue_flag=0;

        for(i=1;i<=n;i++)
        {
            scanf("%ld%ld", &t,&x);
            if(t==1)
            {
                mystack.push(x);
                myqueue.push(x);
                mypq.push(x);

                stack_flag+=1;
                queue_flag+=1;
                prio_queue_flag+=1;
            }
            else if(t==2)
            {
                if(!mystack.empty() && mystack.top()==x )
                {
                    mystack.pop();
                    stack_flag+=1;
                }
                if(!myqueue.empty() && myqueue.front()==x )
                {
                    myqueue.pop();
                    queue_flag+=1;
                }
                if(!mypq.empty() && mypq.top()==x )
                {
                    mypq.pop();
                    prio_queue_flag+=1;
                }
            }
        }
        if((stack_flag == n && queue_flag == n) || (stack_flag == n && prio_queue_flag == n) || (prio_queue_flag == n && queue_flag == n))
            printf("not sure\n");
        else if(prio_queue_flag != n && queue_flag != n && stack_flag != n)
            printf("impossible\n");
        else if(stack_flag == n)
            printf("stack\n");
        else if(queue_flag == n)
            printf("queue\n");
        else
            printf("priority queue\n");

    }
    return 0;
}
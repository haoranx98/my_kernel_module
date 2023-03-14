#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/sched.h>
MODULE_LICENSE("GPL");
MODULE_AUTHOR("haoranx98");
MODULE_DESCRIPTION("A simple example of Linux kernel thread.");
MODULE_VERSION("0.01");

/*void *my_data(char *string){
	printk("My id is %s \n", string);
}*/

static int func(void *data){
while(!kthread_should_stop()){
	printk("My id is %s \n", (char *)data);
msleep(2000);
}
return 0;
}

void *id = "2022E8013282034";

char *thread_name = "my kernel thread of id";

struct task_struct * myThread;

static int __init kernel_threads_init(void) {
	
	myThread = kthread_run(func, id, thread_name);
	if(myThread != NULL){
		printk("thread id is %d\n", myThread->pid);
	}

	return 0;
}
static void __exit kernel_threads_exit(void) {
	kthread_stop(myThread);
 	printk(KERN_INFO "Goodbye, World!My id is 2022E8013282034!\n");
}
module_init(kernel_threads_init);
module_exit(kernel_threads_exit);


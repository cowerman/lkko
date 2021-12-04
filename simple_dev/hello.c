#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/moduleparam.h>

static int myint = 1;
static char *mystr = "hello";
static int myarr[3] = {0, 1, 2};

module_param(myint, int, S_IRUGO);
module_param(mystr, charp, S_IRUGO);
module_param_array(myarr, int, NULL, S_IWUSR|S_IRUSR);

MODULE_PARM_DESC(myint, "This is int type of 1");
MODULE_PARM_DESC(mystr, "This is string of hello");
MODULE_PARM_DESC(myarr, "This is array of int");

static int __init hello_init(void)
{
	int ret = 0, i;

	printk("hello init ...\n");
	printk("myint:%d, mystr:%s\n", myint, mystr);
	for (i = 0; i < sizeof(myarr) / sizeof(myarr[0]); i++) {
		printk("%d ", myarr[i]);
	}
	printk("\n");
	return ret;
}

static void __exit hello_exit(void)
{
	printk("hello exit ...\n");
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_DESCRIPTION("Test for insert hello ko");
MODULE_AUTHOR("qsort987 qsort987@qq.com ");
MODULE_LICENSE("GPL V2");

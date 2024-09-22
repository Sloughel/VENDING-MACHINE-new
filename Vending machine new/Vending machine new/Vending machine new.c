#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>

struct commodity_list {
	char commodity_code;
	int  channel_code;
	int commodity_price;
	int commodity_num;
};
struct commodity_list comm_list[5], user_comm_list[5];

int x;
int ignore;
int u;



int main() {
	struct commodity_list * p;
	p = &comm_list;
	int input(struct commodity_list comm_list[5]);
	x=input(p);
	void buy(struct commodity_list comm_list[5]);
	buy(p);
	p = &user_comm_list;
	int pay(struct commdity_list user_comm_list[5]);
	pay(p);
	printf("如需继续购买，可退出后再进行。\n");
	return 0;
}


int input(struct commodity_list comm_list[5])
{
	int i;
	int j;
	int temp[5] = {0};
	char ch;
	int test;
	int a;
	test = 0;
	
	
	
	

	i = 1;
begin: 
	{
		printf("请依次输入需要摆放的商品类型代号，设置商品通道，设置商品单价，以及摆放的商品数量：(注意，每个参数间需要空格,另外请逐行输入)\n");
	while (i < 5)
	{
		printf("如果需提前退出摆放，请先输入英语输入法中的'...'\n");
		printf("请依次输入需要摆放的商品类型代号，设置商品通道，设置商品单价，以及摆放的商品数量:");

		ignore=scanf("%c%d%d%d", &comm_list[i].commodity_code, &comm_list[i].channel_code, &comm_list[i].commodity_price,
			&comm_list[i].commodity_num);
		if (ignore != 4&&ignore==0)
		{
			printf("输入可能有误！\n");
			printf("如果有误也无所谓，只能说明后面可能会出错，当然也可能不出错(确信)\n");
		}
		
		
		if (comm_list[i].commodity_code == '.')
		{
			
		
			printf("请输入END确认退出，或输入任意其他键以返回\n");
			char end[20] = { "END" };
			while ((ch = getchar()) != '\n' && ch != EOF)

			{
				;
			}
			ignore=scanf("%s", &end);
			if (ignore != 1)
			{
				printf("输入可能有误！\n");
				printf("如果有误也无所谓，只能说明后面可能会出错，当然也可能不出错(确信)\n");
			}
			while ((ch = getchar()) != '\n' && ch != EOF)

			{
				;
			}
			
			if (strcmp(end, "END") == 0)
			{
				goto exit;
			}
			else
			{
				goto begin;
			}
		}
	


		if(comm_list[i].commodity_num>50)
		{
			printf("注意，单个通道的货物总数不超过50\n");
			goto begin;
		}
		//printf("%c", comm_list[i].commodity_code);
		//printf("%d", comm_list[i].channel_code);
		//printf("%d", comm_list[i].commodity_price);
		//printf("%d", comm_list[i].commodity_num);
		while ((ch = getchar()) != '\n' && ch != EOF)

		{
			;
		}
		temp[i] = comm_list[i].channel_code;
		//printf("%d", temp[i]);
		if (i >= 1)
		{
			//printf("程序我啊，在运行了呢\n");
			j = 0;
			while (j < i)
			{
				if (temp[j] == comm_list[i].channel_code&&comm_list[i].commodity_code!=comm_list[j].commodity_code)
				{
					printf("通道重复，请重新输入\n");
					test = 1;
					i--;
					break;
				}
				else if (temp[j] == comm_list[i].channel_code && comm_list[i].commodity_code == comm_list[j].commodity_code)
				{
					

					printf("添加%c商品%d个至%d通道\n", comm_list[i].commodity_code, comm_list[i].commodity_num, comm_list[i].channel_code);
					comm_list[j].commodity_num = comm_list[j].commodity_num + comm_list[i].commodity_num;
					if (comm_list[i].commodity_num < 0)
					{
						printf("注意，商品的数量不能为负！\n");
						comm_list[j].commodity_num= comm_list[j].commodity_num - comm_list[i].commodity_num;
						goto begin;
					}
					if (comm_list[j].commodity_num > 50)
					{
						printf("注意，单个通道的货物总数不超过50\n");
						goto begin;
					}
					
					i--;
					test =2;
					if (comm_list[i].commodity_price != comm_list[j + 1].commodity_price)
					{
						printf("本次输入的单价和%d通道内%c物品的原价不同，是否替换？\n",comm_list[i].channel_code,comm_list[i].channel_code);
						printf("若需替换，请输入'Y',或输入任意其他键表示不替换\n");
						char d;
						d = getchar();
					
						if(d=='Y')
						{
						
							comm_list[j].commodity_price = comm_list[i+1].commodity_price;
							printf("已替换%d通道%c物品单价为%d\n",comm_list[i].channel_code,comm_list[i].commodity_code,comm_list[j].commodity_price);
						}

					}
					goto show;

				
				}
				j++;
			}
			if (comm_list[i].commodity_num < 0)
			{
				printf("注意，商品的数量不能为负！\n");
				goto begin;
			}
			if (test == 0)
			{
				
				a = 0;
				//printf("%d", comm_list[i].commodity_num);
				printf("%d:", comm_list[i].channel_code);
				while (a < comm_list[i].commodity_num)
				{

					printf("%c", comm_list[i].commodity_code);
					a++;

				}
				printf("  %d\n", comm_list[i].commodity_price);
			}
			else
			{
				test = 0;
			}
		show:
			if (test == 2)
			{
				a = 0;
				//printf("%d", comm_list[i].commodity_num);
				printf("商品数量为%d\n", comm_list[j].commodity_num );
				printf("%d:", comm_list[j].channel_code);

				
				while (a < comm_list[j].commodity_num)
				{

					printf("%c", comm_list[j].commodity_code);
					a++;

				}
				printf("  %d\n", comm_list[j].commodity_price);
				test = 0;
			}

			i++;

		}
		
	}
	}
exit:
	printf("摆放结束\n");
	return i-1;
}









void buy(struct commodity_list comm_list[5])
{
	int i;
	int user_num;
	int user_channel;
	int a;
	
	char ch;
	int j;
	int k;
	
	char c[20] = {"continue"};
	char user_code;
	char d[20] = {0};

	k = 0;
	

	begin:
	
	
	while (k < 5)
	{
		printf("商品类型，商品通道，商品单价，商品数量\n");
		//printf("%d", x);
		//printf("%c",comm_list[1].commodity_code);
		for (i = 1; i <= x; i++)
		{
			printf("    %c         %d         %d         %d\n", comm_list[i].commodity_code, comm_list[i].channel_code, comm_list[i].commodity_price,
				comm_list[i].commodity_num);
		}
		printf("如果需要退出购买，请输入'...'\n");
		printf("请输入你需要的商品的代码,通道以及数量：");
		ignore=scanf("%c%d%d", &user_code, &user_channel ,& user_num);
		//printf("ignore的值为%d", ignore);
		if (ignore != 3&&ignore!=1)
		{
			printf("输入可能有误！\n");
			printf("如果有误也无所谓，只能说明后面可能会出错，当然也可能不出错(确信)\n");
			
		}
		while ((ch = getchar()) != '\n' && ch != EOF)

		{
			;
		}
		if (user_code == '.')
		{
			printf("为防止勿入，请先再输入'...'\n");
			printf("再输入END确认退出，或输入任意其他键以返回\n");
			char end[20] = { "END" };
			while ((ch = getchar()) != '\n' && ch != EOF)

			{
				;
			}
			ignore=scanf("%s", &end);
			
			if (ignore != 1)
			{
				printf("输入可能有误！\n");
				printf("如果有误也无所谓，只能说明后面可能会出错，当然也可能不出错(确信)\n");
			}
			while ((ch = getchar()) != '\n' && ch != EOF)

			{
				;
			}

			if (strcmp(end, "END") == 0)
			{
				goto exit;
			}
			else
			{
				goto begin;
			}
		}

		j = 1;
		//printf("user_channel为%d\n",user_channel);
		while (j < 5)
		{
			//printf("comm_list[j].channel_code为%d\n", comm_list[j].channel_code);
			printf("user_channel为%d\n",user_channel);
			if (comm_list[j].channel_code == user_channel)
			{
				goto next;
			}
			j++;
		}
		printf("注意，不存在此通道\n");
		goto begin;

	next:
		//printf("user_code=%c\n", user_code);
		//printf("comm_list[j].commdity_code为%c", comm_list[j].commodity_code);

		if(user_code!=comm_list[j].commodity_code)
		{
			printf("注意，你输入商品不在此通道，请确认是否仍旧购买该通道内的商品\n");
			printf("如果通道对应的商品为你所需要的，输入任意键继续，否则输入'back'\n");
			while ((ch = getchar()) != '\n' && ch != EOF)

			{
				;
			}
			ignore=scanf("%s", d);
			if (ignore != 1)
			{
				printf("输入可能有误！\n");
				printf("如果有误也无所谓，只能说明后面可能会出错，当然也可能不出错(确信)\n");
			}
			while ((ch = getchar()) != '\n' && ch != EOF)

			{
				;
			}
			if ((a=strcmp(d,"back"))==0)
			{
				goto	begin;
			}

		}
		//printf("comm_list[j].commodity_num为%d\n" , comm_list[j].commodity_num);
		//printf("user_num为%d\n", user_num);
		if (comm_list[j].commodity_num < user_num)
		{
			printf("抱歉，购买量超过储存量，请重新购买\n");
			goto begin;
		}

		
		user_comm_list[k] = comm_list[j];
		user_comm_list[k].commodity_num = user_num;
		
		printf("用户购买的数量为%d\n",user_comm_list[k].commodity_num);
		comm_list[j].commodity_num -= user_comm_list[k].commodity_num;
		k++;
	}
exit:
	
	u = 0;
	printf("u为%d\n",u);
	while (u <= k)
	{
		printf("u为%d\n",u);
		printf("请清点购买列表\n");
		if(k=0){
			printf(" 您什么也没有购买\n");
			break;
		}
		printf("商品类型，商品通道，商品单价，商品数量\n");
		printf("u为%d\n",u);
		printf("    %c         %d         %d         %d\n", user_comm_list[u].commodity_code, user_comm_list[u].channel_code, user_comm_list[u].commodity_price,
			user_comm_list[u].commodity_num);
		u++;
	}
	printf("如果想继续购买请输入'continue',或者输入任意键结束\n");
	ignore=scanf("%s",&c);
	if (ignore != 1)
	{
		printf("输入可能有误！\n");
		printf("如果有误也无所谓，只能说明后面可能会出错，当然也可能不出错(确信)\n");
	}
	while ((ch = getchar()) != '\n' && ch != EOF)

	{
		;
	}
	
	if(strcmp(c,"continue")==0)
	{
		goto begin;
	}
		
	return 0;
}

int pay()
{
	int i;
	int pai_money=0;
	char ch;
	int change;
	int change_all=0;
	int change_back;

	for (i = 0; i < u; i++)
	{
		u = 0;
		//printf("u为%d\n",u);
		//printf("user_comm_list[u].commodity_num为%d\n", user_comm_list[u].commodity_num);
		//printf("user_comm_list[u].commodity_price为%d\n", user_comm_list[u].commodity_price);
		pai_money += user_comm_list[u].commodity_num * user_comm_list[u].commodity_price;
	}
	printf("您应付%d元\n", pai_money);
	printf("请投币。可投一元，二元和五元\n");
	printf("投入一元请输入1，投入两元请输入2，投入五元请输入5\n");
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		;
	}
	
	while (change_all<pai_money)
	{
		ignore = scanf("%d", &change);
		if (ignore != 1)
		{
			printf("输入可能有误！\n");
			printf("如果有误也无所谓，只能说明后面可能会出错，当然也可能不出错(确信)\n");
		}
		
		change_all += change;
		printf("您刚才投入了%d\n", change);
		printf("您已投入%d",change_all);
		printf("请继续投币\n");
	}
	printf("投币数量足够，您已投入%d￥\n",change_all);
	change_back = change_all - pai_money;
	if(change_back==0)
	{
		printf("您已完成购买。\n");
	}
	printf("找零%d元\n",change_back);
	
	return 0;
}
	 




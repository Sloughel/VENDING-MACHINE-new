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
	printf("����������򣬿��˳����ٽ��С�\n");
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
		printf("������������Ҫ�ڷŵ���Ʒ���ʹ��ţ�������Ʒͨ����������Ʒ���ۣ��Լ��ڷŵ���Ʒ������(ע�⣬ÿ����������Ҫ�ո�,��������������)\n");
	while (i < 5)
	{
		printf("�������ǰ�˳��ڷţ���������Ӣ�����뷨�е�'...'\n");
		printf("������������Ҫ�ڷŵ���Ʒ���ʹ��ţ�������Ʒͨ����������Ʒ���ۣ��Լ��ڷŵ���Ʒ����:");

		ignore=scanf("%c%d%d%d", &comm_list[i].commodity_code, &comm_list[i].channel_code, &comm_list[i].commodity_price,
			&comm_list[i].commodity_num);
		if (ignore != 4&&ignore==0)
		{
			printf("�����������\n");
			printf("�������Ҳ����ν��ֻ��˵��������ܻ������ȻҲ���ܲ�����(ȷ��)\n");
		}
		
		
		if (comm_list[i].commodity_code == '.')
		{
			
		
			printf("������ENDȷ���˳��������������������Է���\n");
			char end[20] = { "END" };
			while ((ch = getchar()) != '\n' && ch != EOF)

			{
				;
			}
			ignore=scanf("%s", &end);
			if (ignore != 1)
			{
				printf("�����������\n");
				printf("�������Ҳ����ν��ֻ��˵��������ܻ������ȻҲ���ܲ�����(ȷ��)\n");
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
			printf("ע�⣬����ͨ���Ļ�������������50\n");
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
			//printf("�����Ұ�������������\n");
			j = 0;
			while (j < i)
			{
				if (temp[j] == comm_list[i].channel_code&&comm_list[i].commodity_code!=comm_list[j].commodity_code)
				{
					printf("ͨ���ظ�������������\n");
					test = 1;
					i--;
					break;
				}
				else if (temp[j] == comm_list[i].channel_code && comm_list[i].commodity_code == comm_list[j].commodity_code)
				{
					

					printf("���%c��Ʒ%d����%dͨ��\n", comm_list[i].commodity_code, comm_list[i].commodity_num, comm_list[i].channel_code);
					comm_list[j].commodity_num = comm_list[j].commodity_num + comm_list[i].commodity_num;
					if (comm_list[i].commodity_num < 0)
					{
						printf("ע�⣬��Ʒ����������Ϊ����\n");
						comm_list[j].commodity_num= comm_list[j].commodity_num - comm_list[i].commodity_num;
						goto begin;
					}
					if (comm_list[j].commodity_num > 50)
					{
						printf("ע�⣬����ͨ���Ļ�������������50\n");
						goto begin;
					}
					
					i--;
					test =2;
					if (comm_list[i].commodity_price != comm_list[j + 1].commodity_price)
					{
						printf("��������ĵ��ۺ�%dͨ����%c��Ʒ��ԭ�۲�ͬ���Ƿ��滻��\n",comm_list[i].channel_code,comm_list[i].channel_code);
						printf("�����滻��������'Y',������������������ʾ���滻\n");
						char d;
						d = getchar();
					
						if(d=='Y')
						{
						
							comm_list[j].commodity_price = comm_list[i+1].commodity_price;
							printf("���滻%dͨ��%c��Ʒ����Ϊ%d\n",comm_list[i].channel_code,comm_list[i].commodity_code,comm_list[j].commodity_price);
						}

					}
					goto show;

				
				}
				j++;
			}
			if (comm_list[i].commodity_num < 0)
			{
				printf("ע�⣬��Ʒ����������Ϊ����\n");
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
				printf("��Ʒ����Ϊ%d\n", comm_list[j].commodity_num );
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
	printf("�ڷŽ���\n");
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
		printf("��Ʒ���ͣ���Ʒͨ������Ʒ���ۣ���Ʒ����\n");
		//printf("%d", x);
		//printf("%c",comm_list[1].commodity_code);
		for (i = 1; i <= x; i++)
		{
			printf("    %c         %d         %d         %d\n", comm_list[i].commodity_code, comm_list[i].channel_code, comm_list[i].commodity_price,
				comm_list[i].commodity_num);
		}
		printf("�����Ҫ�˳�����������'...'\n");
		printf("����������Ҫ����Ʒ�Ĵ���,ͨ���Լ�������");
		ignore=scanf("%c%d%d", &user_code, &user_channel ,& user_num);
		//printf("ignore��ֵΪ%d", ignore);
		if (ignore != 3&&ignore!=1)
		{
			printf("�����������\n");
			printf("�������Ҳ����ν��ֻ��˵��������ܻ������ȻҲ���ܲ�����(ȷ��)\n");
			
		}
		while ((ch = getchar()) != '\n' && ch != EOF)

		{
			;
		}
		if (user_code == '.')
		{
			printf("Ϊ��ֹ���룬����������'...'\n");
			printf("������ENDȷ���˳��������������������Է���\n");
			char end[20] = { "END" };
			while ((ch = getchar()) != '\n' && ch != EOF)

			{
				;
			}
			ignore=scanf("%s", &end);
			
			if (ignore != 1)
			{
				printf("�����������\n");
				printf("�������Ҳ����ν��ֻ��˵��������ܻ������ȻҲ���ܲ�����(ȷ��)\n");
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
		//printf("user_channelΪ%d\n",user_channel);
		while (j < 5)
		{
			//printf("comm_list[j].channel_codeΪ%d\n", comm_list[j].channel_code);
			printf("user_channelΪ%d\n",user_channel);
			if (comm_list[j].channel_code == user_channel)
			{
				goto next;
			}
			j++;
		}
		printf("ע�⣬�����ڴ�ͨ��\n");
		goto begin;

	next:
		//printf("user_code=%c\n", user_code);
		//printf("comm_list[j].commdity_codeΪ%c", comm_list[j].commodity_code);

		if(user_code!=comm_list[j].commodity_code)
		{
			printf("ע�⣬��������Ʒ���ڴ�ͨ������ȷ���Ƿ��Ծɹ����ͨ���ڵ���Ʒ\n");
			printf("���ͨ����Ӧ����ƷΪ������Ҫ�ģ������������������������'back'\n");
			while ((ch = getchar()) != '\n' && ch != EOF)

			{
				;
			}
			ignore=scanf("%s", d);
			if (ignore != 1)
			{
				printf("�����������\n");
				printf("�������Ҳ����ν��ֻ��˵��������ܻ������ȻҲ���ܲ�����(ȷ��)\n");
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
		//printf("comm_list[j].commodity_numΪ%d\n" , comm_list[j].commodity_num);
		//printf("user_numΪ%d\n", user_num);
		if (comm_list[j].commodity_num < user_num)
		{
			printf("��Ǹ�������������������������¹���\n");
			goto begin;
		}

		
		user_comm_list[k] = comm_list[j];
		user_comm_list[k].commodity_num = user_num;
		
		printf("�û����������Ϊ%d\n",user_comm_list[k].commodity_num);
		comm_list[j].commodity_num -= user_comm_list[k].commodity_num;
		k++;
	}
exit:
	
	u = 0;
	printf("uΪ%d\n",u);
	while (u <= k)
	{
		printf("uΪ%d\n",u);
		printf("����㹺���б�\n");
		if(k=0){
			printf(" ��ʲôҲû�й���\n");
			break;
		}
		printf("��Ʒ���ͣ���Ʒͨ������Ʒ���ۣ���Ʒ����\n");
		printf("uΪ%d\n",u);
		printf("    %c         %d         %d         %d\n", user_comm_list[u].commodity_code, user_comm_list[u].channel_code, user_comm_list[u].commodity_price,
			user_comm_list[u].commodity_num);
		u++;
	}
	printf("������������������'continue',�����������������\n");
	ignore=scanf("%s",&c);
	if (ignore != 1)
	{
		printf("�����������\n");
		printf("�������Ҳ����ν��ֻ��˵��������ܻ������ȻҲ���ܲ�����(ȷ��)\n");
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
		//printf("uΪ%d\n",u);
		//printf("user_comm_list[u].commodity_numΪ%d\n", user_comm_list[u].commodity_num);
		//printf("user_comm_list[u].commodity_priceΪ%d\n", user_comm_list[u].commodity_price);
		pai_money += user_comm_list[u].commodity_num * user_comm_list[u].commodity_price;
	}
	printf("��Ӧ��%dԪ\n", pai_money);
	printf("��Ͷ�ҡ���ͶһԪ����Ԫ����Ԫ\n");
	printf("Ͷ��һԪ������1��Ͷ����Ԫ������2��Ͷ����Ԫ������5\n");
	while ((ch = getchar()) != '\n' && ch != EOF)
	{
		;
	}
	
	while (change_all<pai_money)
	{
		ignore = scanf("%d", &change);
		if (ignore != 1)
		{
			printf("�����������\n");
			printf("�������Ҳ����ν��ֻ��˵��������ܻ������ȻҲ���ܲ�����(ȷ��)\n");
		}
		
		change_all += change;
		printf("���ղ�Ͷ����%d\n", change);
		printf("����Ͷ��%d",change_all);
		printf("�����Ͷ��\n");
	}
	printf("Ͷ�������㹻������Ͷ��%d��\n",change_all);
	change_back = change_all - pai_money;
	if(change_back==0)
	{
		printf("������ɹ���\n");
	}
	printf("����%dԪ\n",change_back);
	
	return 0;
}
	 




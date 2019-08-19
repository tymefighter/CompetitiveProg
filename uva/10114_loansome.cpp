#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int dur, num_dep_rec, i, flag, month, mon_ch;
	float down, amt, car_val, loan, dep, prev_dep, val;



	while(scanf("%d %f %f %d", &dur, &down, &amt, &num_dep_rec))
	{
		if(dur < 0)
			break;
		
		car_val = down + amt;
		loan = amt;
		val = amt/dur;
		month = 0;
		flag = 0;

		scanf("%d %f",&mon_ch, &dep);
		car_val = car_val*(1-dep);

		if(car_val > loan)
		{
			/////////////
			printf("0 months\n");
			flag = 1;
		}

		//printf("%d %f %f\n",month, car_val, loan);////

		month++;
		prev_dep = dep;

		for(i = 0;i <= num_dep_rec - 1;i++)
		{
			if(i == num_dep_rec - 1)
			{
				mon_ch = dur;
			}
			else
			{
				scanf("%d %f",&mon_ch, &dep);
			}

			while(month < mon_ch)
			{
				car_val = car_val*(1 - prev_dep);
				loan -= val;

				//printf("%d %f %f\n",month, car_val, loan);////
				if(car_val > loan)
				{
					//////////////
					if(flag == 0)
					{
						if(month == 1)
							printf("1 month\n");
						else
							printf("%d months\n",month);

						flag = 1;
					}
				}
				month++;
			}

			/*if(mon_ch ==)
			{
				printf("yo\n");
			}*/

			car_val = car_val*(1-dep);
			loan -= val;
			//printf("%d %f %f\n",month, car_val, loan);////
			month++;

			if(car_val > loan)
			{
				///////////////
				if(flag == 0)
				{
					if(month == 1)
						printf("1 month\n");
					else
						printf("%d month\n", month);

					flag = 1;
				}
			}

			prev_dep = dep;
		}

		/*while(i <= num_dep_rec - 2)
		{
			scanf("%d %f",&mon_ch, &dep);
			i++;
		}*/

	}

	return 0;
}

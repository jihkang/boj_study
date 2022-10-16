/**
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다.
다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
*/

#include <stdio.h>

int		check_rotate(int c, int six_cnt, int nine_cnt)
{
	if (six_cnt > nine_cnt && c == 6)
		return (1);
	else if (six_cnt < nine_cnt && c == 9)
		return (1);
	return (0);
}

void	nine_or_six(int c, int *used)
{

	if (c == 6 && check_rotate(c, used[6], used[9]))
		used[9]++;
	else if (c == 9 && check_rotate(c, used[6], used[9]))
		used[6]++;
	else
		used[c]++;
}

void	solve(int res, int *used)
{
	int	mod;

	if (res <= 0)
		return ;
	mod = res % 10;
	solve(res / 10, used);
	if (mod == 6 || mod == 9)
		nine_or_six(mod, used);
	else
		used[mod]++;
}

int main(void)
{
	int	n;
	int	used[10] = {0,};
	int	max = 0;

	scanf("%d",&n);
	solve(n, used);
	for(int i = 0; i < 10; i++)
	{
		if (max < used[i])
			max = used[i];
	}
	printf("%d\n", max);
	return 0;
}

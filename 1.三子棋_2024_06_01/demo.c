/*══════════════════════════════════════════════════════════╗
*作    者：xyangzhengx                                      ║
*门    派：逍遥派                                           ║
*CSND地址：https://blog.csdn.net/weixin_43949535            ║
**GitHub ：https://github.com/xyangzhengx/C-_CodeCruiser.git║
/*══════════════════════════════════════════════════════════╝
*/                                                               
#include "game.h"
void menu()
{
	printf("**************************\n");
	printf("*******   0.exit   *******\n");
	printf("*******   1.play   *******\n");
	printf("**************************\n");
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("Please choose:");
		scanf("%d",&input);
		switch (input)
		{
			case 0:
				printf("Exiting game...\n");
				break;
			case 1:
				game();
				break;
			default:
				printf("Input is error!\n");
				break;
		}
	} while (input);
	return 0;
}
/*
 * テストの点数を入力させ名前以外のそれぞれでソートを行うプログラム
 * 点数表をテキストファイルにして出力をする
 */

#include <stdio.h>

/*
 * 構造体person_dataを宣言
 */
typedef struct pereson_data{
	char name[256];
	int japanese, english, math, sum;
	double ave;
}person_data;

/*
 * テストの点数を入力させる（最大50人）
 * 0が入力された時点で入力終了
 */
void input(person_data *data1)
{
	int i;

	for (i = 0; i < 50; i++){
		printf("> 名前とテストの点数を入力してください（0を入力して終了）\n");
		printf("> 名前 : ");
		scanf("%s", (data1 + i)->name);
		if ((data1 + i)->name[0] == '0'){
			break;
		}
		printf("> 国語 : ");
		scanf("%d", &((data1 + i)->japanese));
		printf("> 英語 : ");
		scanf("%d", &((data1 + i)->english));
		printf("> 数学 : ");
		scanf("%d", &((data1 + i)->math));

		(data1 + i)->sum = (data1 + i)->japanese + (data1 + i)->english + (data1 + i)->math;
		(data1 + i)->ave = (double)((data1 + i)->sum) / 3;
	}
}

/*
 * 入力された点数を何順にソートするかを選ばせる
 * 入力されたソート方法の番号を戻す
 */
int input_sort_type(int *end)
{
	int sort_type;

	printf("\n> 何順にソートしますか\n");
	printf("> 1 : 国語順\n  2 : 英語順\n  3 : 数学順\n  4 : 合計順\n  5 : 平均順\n  6 : ファイル出力\n  0 : 終了\n> ");
	scanf("%d", &sort_type);

	if (sort_type == 0){
		*end = 0;
	}

	return sort_type;
}

/*
 * 国語順にソートする
 */
void sort_japanese(person_data *data1)
{
	int i, j;
	person_data tmp;

	for (i = 0; (data1 + i + 1)->name[0] != '0'; i++){
		for (j = i + 1; (data1 + j)->name[0] != '0'; j++){
			if ((data1 + i)->japanese < (data1 + j)->japanese){
				tmp = *(data1 + j);
				*(data1 + j) = *(data1 + i);
				*(data1 + i) = tmp;
			}
		}
	}
}

/*
 * 英語順にソートする
 */
void sort_english(person_data *data1)
{
	int i, j;
	person_data tmp;

	for (i = 0; (data1 + i + 1)->name[0] != '0'; i++){
		for (j = i + 1; (data1 + j)->name[0] != '0'; j++){
			if ((data1 + i)->english < (data1 + j)->english){
				tmp = *(data1 + j);
				*(data1 + j) = *(data1 + i);
				*(data1 + i) = tmp;
			}
		}
	}
}

/*
 * 数学順にソートする
 */
void sort_math(person_data *data1)
{
	int i, j;
	person_data tmp;

	for (i = 0; (data1 + i + 1)->name[0] != '0'; i++){
		for (j = i + 1; (data1 + j)->name[0] != '0'; j++){
			if ((data1 + i)->math < (data1 + j)->math){
				tmp = *(data1 + j);
				*(data1 + j) = *(data1 + i);
				*(data1 + i) = tmp;
			}
		}
	}
}

/*
 * 合計順にソートする
 */
void sort_sum(person_data *data1)
{
	int i, j;
	person_data tmp;

	for (i = 0; (data1 + i + 1)->name[0] != '0'; i++){
		for (j = i + 1; (data1 + j)->name[0] != '0'; j++){
			if ((data1 + i)->sum < (data1 + j)->sum){
				tmp = *(data1 + j);
				*(data1 + j) = *(data1 + i);
				*(data1 + i) = tmp;
			}
		}
	}
}

/*
 * 平均順にソートする
 */
void sort_ave(person_data *data1)
{
	int i, j;
	person_data tmp;

	for (i = 0; (data1 + i + 1)->name[0] != '0'; i++){
		for (j = i + 1; (data1 + j)->name[0] != '0'; j++){
			if ((data1 + i)->ave < (data1 + j)->ave){
				tmp = *(data1 + j);
				*(data1 + j) = *(data1 + i);
				*(data1 + i) = tmp;
			}
		}
	}
}

/*
 * テストの点数表をファイルに出力する
 */
void output_file(FILE *fp, person_data *data1)
{
	int i;

	fp = fopen("成績表.txt", "w");

	fprintf(fp, "\t\t国語\t英語\t数学\t合計\t平均\n");

	for (i = 0; (data1 + i)->name[0] != '0'; i++){
		fprintf(fp, "%-15s%3d点%6d点%6d点%7d点%7.1f点\n", (data1 + i)->name, (data1 + i)->japanese, (data1 + i)->english, (data1 + i)->math, (data1 + i)->sum, (data1 + i)->ave);
	}

	fclose(fp);
}

/*
 * 何順にソートしたかを表示する
 * out_titleが6の時はファイルを出力する
 */
void output_title(int out_title, person_data *data1, FILE *fp)
{
	switch (out_title){
		case 1:
			sort_japanese(data1);
			printf("> 国語順\n");
			break;

		case 2:
			sort_english(data1);
			printf("> 英語順\n");
			break;

		case 3:
			sort_math(data1);
			printf("> 数学順\n");
			break;

		case 4:
			sort_sum(data1);
			printf("> 合計順\n");
			break;
		
		case 5:
			sort_ave(data1);
			printf("> 平均順\n");
			break;

		case 6:
			output_file(fp, data1);
			printf("> ファイル”成績表.txt”を出力しました\n");
			break;
	}
}

/*
 * 出力
 * ソート結果を表示する
 */
void output(person_data *data1)
{
	int i;

	printf("\t\t国語\t英語\t数学\t合計\t平均\n");
	
	for (i = 0; (data1 + i)->name[0] != '0'; i++){
		printf("> %-13s%3d点%6d点%6d点%7d点%7.1f点\n", (data1 + i)->name, (data1 + i)->japanese, (data1 + i)->english, (data1 + i)->math, (data1 + i)->sum, (data1 + i)->ave);
	}
}

/*
 * 関数を呼び出す
 */
int main()
{
	int out_title;
	int end = 1;
	person_data data1[50];
	FILE *fp;

	/*
	 * input_sort_type関数で0が入力されるまで繰り返す
	 */
	input(data1);
	while (end){
		out_title = input_sort_type(&end);
		if (end == 0){
			break;
		}
		output_title(out_title, data1, fp);
		output(data1);
	}

	return 0;
}

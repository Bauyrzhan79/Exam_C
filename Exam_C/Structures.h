
#define length 21

struct vremya
{
	int chas;
	int min;
	int sek;
};

struct mashina
{
	char marka[length];
	char model[length];
	char dvigatel[length];
	char kuzov[length];
	char kpp[length];
	char privod[length];
	char rul[length];
	char nomer[length];
};

struct pochtMashina
{
	int nomMarshrut;
	mashina nomerMash;
	char punktNazn[length];
	vremya vremVyezd;
	vremya vremPribyt;
	int vremObmen;
};
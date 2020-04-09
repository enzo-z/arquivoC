#include <stdio.h>
#include <stdlib.h>
struct tel {
	int ddd, cel, trab, casa;
};
struct regagenda{
	char nome[100], endereco[300];
	struct tel fone;
};
struct regagenda agenda;
int x;
main (){
	FILE *exemplo;
	exemplo = fopen("TesteBrito.dat", "a+b");
	if (exemplo==NULL){
		printf("NAO FOI POSSIVEL CRIAR O ARQUIVO!");
		getchar();
		exit(0);
	}
	else{
		printf("Preencha sua agenda!\nInsira seu nome: ");
		scanf("%s", &agenda.nome);
		printf("Insira seu endere�o: ");
		scanf("%s", &agenda.endereco);
		printf("Insira seu DDD (MAX DE 2 DIGITOS): ");
		scanf("%d", &agenda.fone.ddd);
		printf("Insira seu telefone celular: ");
		scanf("%d", &agenda.fone.cel);
		printf("Insira seu telefone de casa: ");
		scanf("%d", &agenda.fone.casa);
		printf("Insira seu telefone do trabalho [SE NAO TIVER, PRESSIONE 0]: ");
		scanf("%d", &agenda.fone.trab);
		fprintf(exemplo, "Nome: ");
		fwrite(&agenda.nome, sizeof(char), 100, exemplo); 
		fprintf(exemplo,"\n");
		fprintf(exemplo,"\tEndereco: ");
		fwrite(&agenda.endereco, sizeof(char), 300, exemplo);
		fprintf(exemplo, "\n");
		fprintf(exemplo, "DDD: ");
		fwrite(&agenda.fone.ddd, sizeof(int), 2, exemplo);
		fprintf(exemplo, "\tTelefone de casa:   ");
		fwrite(&agenda.fone.casa, sizeof(int), 8, exemplo); // 2446 - 6435 = 8 3435- 1310
		fprintf(exemplo, "\tTelefone celular:   ");
		fwrite(&agenda.fone.cel, sizeof(double), 9, exemplo);			// 96839- 4146 9  975761963
		fprintf(exemplo,"\tTelefone do trabalho: "); 
		if (agenda.fone.trab != 0)
			fwrite(&agenda.fone.trab, sizeof(double), 8, exemplo); // Usei de exemplo o telefone de uma pizzaria, tendo 8 digitos		
	}
	fclose(exemplo); 
	printf("\n\n\nPressione 1 para abrir sua agenda!");
	scanf("%d", &x);
	printf("Loading...\n\n________________________________________________________________________________________________-");
	exemplo = fopen("TesteBrito.dat", "rb");
	if (exemplo==NULL){
		printf("NAO FOI POSSIVEL ABRIR ARQUIVO\nARQUIVO NAO EXISTE");
		getchar();
		exit(0);
	}
	else{
		rewind(exemplo); 
		printf("\nNome:  %s", agenda.nome);
		fread(&agenda.nome, sizeof(char), 100, exemplo);
		printf("\n\nEndereco: %s", agenda.endereco);
		fread(&agenda.endereco, sizeof(char), 300, exemplo);
		printf("\n\n\tDDD: %d", agenda.fone.ddd);
		fread(&agenda.fone.ddd, sizeof(int), 2, exemplo);
		printf("\tTelefone casa: %d", agenda.fone.casa);
		fread(&agenda.fone.casa, sizeof(int), 8, exemplo);
		printf("\tCelular: %d", agenda.fone.cel);
		fread(&agenda.fone.cel, sizeof(double), 9, exemplo);
		printf("\tTrabalho: ",  agenda.fone.casa);
		if (agenda.fone.trab != 0);
			fread(&agenda.fone.trab, sizeof(double), 8, exemplo);
		printf("\n_______________________________________________________________________________________________________");
		
	}
	fclose(exemplo);
}

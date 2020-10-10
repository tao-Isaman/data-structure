#pragma once
#include "LinkedList.h"
class LineEditor : public LinkedList
{
public:
	void Display(FILE *fp = stdout) {
		int i=0;
		for( Node *p = getHead() ; p != NULL ; p=p->getLink(), i++ ) {
			fprintf(stderr, "%3d: ", i);
			p->display(fp);
		}
	}

	void InsertLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  입력행 번호: ");
		scanf("%d", &position);
		printf("  입력행 내용: ");
		fflush(stdin);	
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		insert(position, new Node( line ));
	}
	void DeleteLine() {
		printf("  삭제행 번호: ");
		int position;
		scanf("%d",&position);

		remove( position );
	}
	void ReplaceLine() {
		int position;
		char line[MAX_CHAR_PER_LINE];
		printf("  변경행 번호: ");
		scanf("%d", &position);
		printf("  변경행 내용: ");
		fflush(stdin);	
		fgets(line, MAX_CHAR_PER_LINE, stdin);

		replace(position, new Node( line ));
	}

	void LoadFile( char *fname ) {
		FILE *fp = fopen(fname,"r");
		if( fp != NULL ){
			char line[MAX_CHAR_PER_LINE];
			while(fgets(line, MAX_CHAR_PER_LINE, fp))
				insert(size(), new Node( line ) );
			fclose(fp);
		}
	}
	void StoreFile( char *fname ) {
		FILE *fp = fopen( fname,"w" );
		if( fp != NULL ){
			Display( fp );
			fclose(fp);
		}
	}
};


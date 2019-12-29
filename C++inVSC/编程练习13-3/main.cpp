#include "dma.h"
#include <iostream>

int main(void)
{

	ABC * pObj[4];
	baseDMA b1 = baseDMA("Label of Royal", 5);
	pObj[0] = &b1;
	pObj[0]->view();
	lacksDMA l1("LacksDMA_Red", "Label of Lacks", 10);
	pObj[1] = &l1;
	pObj[1]->view();
	hasDMA h1("HasDMA_Style", "Label of style", 15);
	pObj[2] = & h1;
	pObj[2]->view();

	return 0;
}

class BST
{
	public:
		BST();
		~BST();
		bool search(int data);
		bool add(int data);
		void print(int tipo);
		bool del(int dato);
		int count();
    int wherelevelIam(int d);
    void ancestros(int d);
    int height();
	private:
		nodeT *root;
		void preorden(nodeT *r);
		void inorden(nodeT *r);
		void postorden(nodeT *r);
		void delAll(nodeT *r);
		int howManyChildren(nodeT *r);
		int pred(nodeT *r);
		int succ(nodeT *r);
		int countR(nodeT *r);
		void printLeaves(nodeT *r);
    void nivelxnivel(nodeT *r);
};

BST::BST()
{
	root = NULL;
}

void BST::delAll(nodeT *r)
{
	if (r != NULL)
	{
		delAll(r->getLeft());
		delAll(r->getRight());
		delete r;
	}
}

BST::~BST()
{
	delAll(root);
}

bool BST::search(int data)
{
	nodeT *aux = root;
	while (aux != NULL)
	{
		if (aux->getData() == data)
		{
			return true;
		}
		aux = (aux->getData() > data) ? aux->getLeft() : aux->getRight();
	}
	return false;
}

bool BST::add(int data)
{
	if (root == NULL)
	{
		root = new nodeT(data);
		return true;
	}
	nodeT *dad = NULL;
	nodeT *aux = root;
	while (aux != NULL)
	{
		if (aux->getData() == data)
		{
			return false;
		}
		dad = aux;
		aux = (aux->getData() > data) ? aux->getLeft() : aux->getRight();
	}
	(dad->getData() > data) ? dad->setLeft(new nodeT(data)) : dad->setRight(new nodeT(data));
	return true;
}

void BST::preorden(nodeT *r)
{
	if (r != NULL)
	{
		cout << r->getData() << " ";
		preorden(r->getLeft());
		preorden(r->getRight());
	}
}

void BST::inorden(nodeT *r)
{
	if (r != NULL)
	{
		inorden(r->getLeft());
		cout << r->getData() << " ";
		inorden(r->getRight());
	}
}

void BST::postorden(nodeT *r)
{
	if (r != NULL)
	{
		postorden(r->getLeft());
		postorden(r->getRight());
		cout << r->getData() << " ";
	}
}

void BST::printLeaves(nodeT *r)
{
  if (r != NULL)
	{
		if (r->getLeft() == NULL && r->getRight() == NULL)
			cout << r->getData() << " ";
		printLeaves(r->getLeft());
		printLeaves(r->getRight());
	}
}

void BST::print(int tipo)
{
	switch (tipo)
	{
		case 1: preorden(root);
				break;
		case 2: inorden(root);
				break;
		case 3: postorden(root);
				break;
		case 4: printLeaves(root);
				break;
    case 5: nivelxnivel(root);
	}
	cout << endl;
}

int BST::howManyChildren(nodeT *r)
{
	int cont = 0;
	if (r->getLeft() != NULL)
	{
		cont++;
	}
	if (r->getRight() != NULL)
	{
		cont++;
	}
	return cont;
}

int BST::pred(nodeT *r)
{
	nodeT *aux = r->getLeft();
	while (aux->getRight() != NULL)
	{
		aux = aux->getRight();
	}
	return aux->getData();
}

int BST::succ(nodeT *r)
{
	nodeT *aux = r->getRight();
	while (aux->getLeft() != NULL)
	{
		aux = aux->getLeft();
	}
	return aux->getData();
}

bool BST::del(int data)
{
	nodeT *dad = NULL;
	nodeT *aux = root;
	while (aux != NULL && aux->getData() != data)
	{
		dad = aux;
		aux = (aux->getData() > data) ? aux->getLeft() : aux->getRight();
	}
	if (aux == NULL)
	{
		return false;
	}
	int cont = howManyChildren(aux);
	switch (cont)
	{
		case 0 : if (dad == NULL)
				{
					root = NULL;
				}
				else
				{
					dad->getData() > data ? dad->setLeft(NULL) : dad->setRight(NULL);
				}
				delete aux;
				break;
		case 1 : if (dad == NULL)
				{
					root = aux->getLeft() != NULL ? aux->getLeft() : aux->getRight();
				}
				else
				{
					if (dad->getData() > data)
					{
						if (aux->getLeft() != NULL)
						{
							dad->setLeft(aux->getLeft());
						}
						else
						{
							dad->setLeft(aux->getRight());
						}
					}
					else
					{
						if (aux->getLeft() != NULL)
						{
							dad->setRight(aux->getLeft());
						}
						else
						{
							dad->setRight(aux->getRight());
						}
					}
				}
				delete aux;
				break;
		case 2 :
				int d = succ(aux);
				del(d);
				aux->setData(d);
				break;
	}
	return true;

}

int BST::countR(nodeT *r)
{
	if (r == NULL)
		return 0;
	return 1 + countR(r->getLeft()) + countR(r->getRight());
}

int BST::count()
{
	return countR(root);
}

int BST::wherelevelIam(int d) {
	int count = 0;
  nodeT *aux = root;
	while (aux != NULL)
	{
		if (aux->getData() == d)
		{
			return count;
		}
		aux = (aux->getData() > d) ? aux->getLeft() : aux->getRight();
    count++;
	}
  return -1;
}

void BST::ancestros(int d) {
  stack<int> stack1;
  nodeT *aux = root;

  stack1.push(aux->getData());
	while (aux != NULL)
	{
		if (aux->getData() == d)
		{
			break;
		}
    stack1.push(aux->getData());
		aux = (aux->getData() > d) ? aux->getLeft() : aux->getRight();
  }

  while (stack1.size()-1) {
    cout << stack1.top();
    stack1.pop();
  }
}

int BST::height() {
  nodeT *r = root;
  stack<int> stack1;
}

void BST::nivelxnivel(nodeT *r) {
  queue<int> queue1;
  queue1.push(r->getData());
}

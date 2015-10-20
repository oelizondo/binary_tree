class nodeT
{
	public:
		nodeT(int data);
		int getData();
		nodeT* getLeft();
		nodeT* getRight();
		void setData(int data);
		void setLeft(nodeT *left);
		void setRight(nodeT *right);

	private:
		int data;
		nodeT *left;
		nodeT *right;
};

nodeT::nodeT(int data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
}

int nodeT::getData()
{
	return data;
}

nodeT* nodeT::getLeft()
{
	return left;
}

nodeT* nodeT::getRight()
{
	return right;
}

void nodeT::setData(int data)
{
	this->data = data;
}

void nodeT::setLeft(nodeT *left)
{
	this->left = left;
}

void nodeT::setRight(nodeT *right)
{
	this->right = right;
}

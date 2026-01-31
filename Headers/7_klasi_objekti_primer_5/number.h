class Numbers		// Class definition
{
public:				// Can be accessed by a "client".
	Numbers();		// Class "constructor"
	void display();
	void update();
private:			// Cannot be accessed by "client"
	char name[30];
	int a;
	float b;
};

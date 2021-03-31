class Something_const
{
public:
    int m_value;
    Something_const(): m_value(0){}
    void setValue(int value) { m_value = value; }
    int getValue() const{ return m_value ; }
};

class Something
{
public:
    int m_value;
    Something(): m_value(0){}
    void setValue(int value) { m_value = value; }
    int getValue() { return m_value ; }
};
 
int main()
{
    const Something_const something; // calls default constructor
 
    something.m_value = 5; // compiler error: violates const
    something.setValue(5); // compiler error: violates const
	something.getValue(); // compiler error: violates const
 
    return 0;
}

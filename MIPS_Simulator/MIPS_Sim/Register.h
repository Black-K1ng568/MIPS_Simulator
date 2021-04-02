#pragma once
class Register
{
public:
	bool* getRegValueBool();
	int getRegValueInt();
	void setRegValue( bool *array);
	void incrementRegValue();
	void addValue();

private:
	bool reg[32] = {0};
};


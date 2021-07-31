#include <fstream>
#include <vector>
#include <cstdint>


int main(int _nargs, const char* _args[])
{
	
	std::vector<uint8_t> _bytes{};
	
	{
		std::ifstream _in{ _args[1], std::ios::bin  };
		while (_in)
		{
			_bytes.push_back(_in.get());
		};
	};
	
	std::ofstream _out{ "flipped.out", std::ios::bin }; 
	
	if((_bytes.size() % 2) == 1)
	{
		_bytes.push_back(0);
	};
	
	for (auto it = _bytes.begin(); it != _bytes.end(); it += 2)
	{
		_out.write(*(it + 1));
	};
	
	_out.close();
	return 0;
};
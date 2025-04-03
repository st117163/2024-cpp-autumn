#include "Dataset.h"

Dataset::Dataset(const std::string& file_path,
	char delimiter,
	bool has_header,
	bool has_index,
	const std::vector<std::string>& custom_col_names)
{
	read_file(file_path, delimiter, has_header, has_index);

	if (!custom_col_names.empty())
	{
		if (custom_col_names.size() != data.size() - 1)
		{
			throw std::runtime_error("Number of custom column names doesn't match number of columns");
		}
		for (size_t i = 1; i < data.size(); i++)
		{
			data[i].name = custom_col_names[i - 1];
		}
	}
}

void Dataset::read_file(const std::string& file_path, char delimiter, bool has_header, bool has_index)
{
	std::ifstream file(file_path);
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file: " + file_path);
	}

	std::string line;
	size_t line_num = 0;
    Column col;
	while (std::getline(file, line))
	{
			if (!line.empty() && line.back() == '\r')
			{
				line.pop_back();
			}

			std::vector<std::string> value = split(line, delimiter);
			if (!has_index)
			{
				if (has_header)
				{
					if (line_num == 0)
					{
						value.insert(value.begin(), "");
					}
					else
					{
						value.insert(value.begin(), std::to_string(line_num - 1));
					}
				}
				else
				{
					value.insert(value.begin(), std::to_string(line_num));
				}
			}

			if (line_num == 0)
			{
				if (has_header)
				{
					for (size_t i = 0; i < value.size(); i++)
					{
                        col.name = value[i];
						data.push_back(col);
					}
				}
				else
				{   
                    col.name = "";
					data.push_back(col);
					for (size_t i = 1; i < value.size(); i++)
					{
                        Column col;
                        col.name = "col" + std::to_string(i);
						data.push_back(col);
					}
                    for (size_t i = 0; i < value.size(); i++)
			            {
				            data[i].values.push_back(value[i]);
			            }
				}
			}

			else
            {
                for (size_t i = 0; i < value.size(); i++)
			    {
				    data[i].values.push_back(value[i]);
			    }

            }
            line_num++;
		}

	size = data.empty() ? 0 : (data.size()-1) * data[0].values.size();
}

std::vector<std::string> Dataset::split(std::string line, char delimiter)
{
	std::vector<std::string> result;
	std::string current;

	for (char c : line)
	{
		if (c != delimiter)
		{
			current += c;
		}
		else
		{
			result.push_back(current);
			current.clear();
		}
	}

	if (!line.empty())
	{
		result.push_back(current);
	}
	return result;
}

// Вывод первых n строк
void Dataset::head(int n) const
{
	if (n <= 0) return;
    n = std::min(n, static_cast<int>(data[0].values.size()));
	// Вывод заголовков
	for (size_t i = 0; i < data.size(); i++)
    {
		std::cout << std::setw(12) << data[i].name << " ";
	}
	std::cout << std::endl << std::string(80, '-') << std::endl;

	// Вывод данных
	for (size_t i = 0; i < n; i++)
    {
		for (size_t j = 0; j < data.size(); j++)
        {
			std::cout << std::setw(12) << data[j].values[i] << " ";
		}
		std::cout << "\n";
	}
}

// Вывод последних n строк
void Dataset::tail(int n) const {
	if (n <= 0) return;
    n = std::min(n, static_cast<int>(data[0].values.size()));
	// Вывод заголовков
	for (size_t i = 0; i < data.size(); i++)
    {
		std::cout << std::setw(12) << data[i].name << " ";
	}
	std::cout << std::endl << std::string(80, '-') << std::endl;


	for (size_t i = data[0].values.size() - n; i < data[0].values.size(); i++)
    {
		for (size_t j = 0; j < data.size(); j++)
        {
			std::cout << std::setw(8) << data[j].values[i] << " ";
		}
		std::cout << std::endl;
	}
}

// Вставка строки
void Dataset::insert(size_t index, const std::vector<std::string>& line) {
	if (line.size() + 1 != data.size())
    {
		throw std::runtime_error("Row size doesn't match number of columns");
	}

	if (index > data[0].values.size()) index = data[0].values.size();

	for (size_t i = 1; i < data.size(); i++)
    {
		data[i].values.insert(data[i].values.begin() + index, line[i - 1]);
	}
    data[0].values.push_back(std::to_string(data[0].values.size()));
	size += data.size()-1;
}

// Удаление строки
void Dataset::remove(size_t index)
{
	if (index >= size)
    {
		throw std::out_of_range("Index out of range");
	}

	for (size_t i = 1; i < data.size(); i++)
    {
		data[i].values.erase(data[i].values.begin() + index);
	}
	data[0].values.pop_back();
	size -= data.size()-1;
}
// Конвертация строки в double
double Dataset::to_double(const std::string& s) const
{
    if (s == "")
    {
        return 0;
    }
    else
    {
	    try
        {
		    return std::stod(s);
	    }
	    catch (...)
        {
		    throw std::runtime_error("Cannot convert '" + s + "' to numeric value");
	    }
    }
}

// Статистика по столбцу
void Dataset::describe(const std::string& column_name) const
{
	// Поиск столбца по имени
	size_t col_index = -1;
	for (size_t i = 0; i < data.size(); i++)
    {
		if (data[i].name == column_name)
        {
			col_index = i;
			break;
		}
	}

	if (col_index == static_cast<size_t>(-1))
    {
		std::cout << "Column '" << column_name << "' not found!\n";
		return;
	}

    std::vector<std::string> numbers = data[col_index].values;

	// Вычисление статистик
	double sum = 0.0;
	double sum_sq = 0.0;
	double min_val = to_double(numbers[0]);
	double max_val = to_double(numbers[0]);

	for (size_t i = 0; i < numbers.size(); i++)
    {
		double num = to_double(numbers[i]);
		sum += num;
		sum_sq += num * num;
		min_val = std::min(min_val, num);
		max_val = std::max(max_val, num);
	}

	const double mean = sum / numbers.size();
	const double variance = (sum_sq / numbers.size()) - (mean * mean);
	const double std_dev = std::sqrt(variance);

	// Вывод
	std::cout << "\nStatistics for '" << column_name << "':\n"
		<< "  Count:    " << numbers.size() << "\n"
		<< "  Min:      " << min_val << "\n"
		<< "  Max:      " << max_val << "\n"
		<< "  Mean:     " << mean << "\n"
		<< "  Std Dev:  " << std_dev << "\n";
}

// Оператор доступа к строке
std::vector<std::string> Dataset::operator[](size_t index) const
{
	if (index >= data[0].values.size())
    {
		throw std::out_of_range("Index out of range");
	}

	std::vector<std::string> line;
	for (size_t i = 1; i < data.size(); i++)
    {
		line.push_back(data[i].values[index]);
	}
	return line;
}
/*// Оператор доступа к элементу
std::string Dataset::operator(size_t line_index, size_t col_index) const {
	if (line_index >= data[0].values.size() || col_index >= data.size()) {
		throw std::out_of_range("Index out of range");
	}
	return data[col_index].values[line_index];
}*/
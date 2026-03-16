# Переменные для удобства
CXX      := g++
CXXFLAGS := -std=c++11 -Wall
TARGET   := program

# Список исходных файлов (разбит по строкам для красоты)
SRCS     := main.cpp \
            src/Function/Function.cpp \
            src/LinearFunction/LinearFunction.cpp \
            src/QuadraticFunction/QuadraticFunction.cpp

# По умолчанию: собираем и запускаем
all: build run

# Компиляция
build:
	@echo "Compiling..."
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Запуск
run:
	@echo "Running $(TARGET):"
	@echo "------------------"
	@./$(TARGET)

# Очистка (хороший тон)
clean:
	rm -f $(TARGET)

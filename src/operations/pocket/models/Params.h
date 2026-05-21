// Params.h
#pragma once

namespace pocket {
enum class PocketType {
    Circular = 1,   // Круговой карман
    Rectangular = 2 // Прямоугольный карман
};

enum class InsertionType {
    Spiral = 1,   // Врезание по спирали
    Pendulum = 2, // Маятниковое врезание
    Vertical = 3  // Вертикальное врезание
};

enum class MachiningType {
    Planar = 1, // Обработка в плоскости
    Helical = 2 // Обработка спирально
};

struct Params {
    PocketType type; // Тип кармана

    int ToolNumber;      // Номер инструмента
    double Feed;         // Подача
    double SpindleSpeed; // Скорость вращения шпинделя

    double X;  // Координата X центра кармана
    double Y;  // Координата Y центра кармана
    double Z;  // Координата Z верхней поверхности заготовки
    double Z1; // Глубина кармана
    double DZ; // Глубина одного прохода

    double radius; // Радиус для кругового кармана
    double length; // Длина для прямоугольного кармана
    double width;  // Ширина для прямоугольного кармана

    InsertionType insertion; // Тип врезания
    double insertionR;       // Радиус врезания
    double insertionH;       // Высота врезания
    double insertionAngle;   // Угол врезания

    MachiningType machining; // Тип обработки для кругового кармана
};
} // namespace pocket
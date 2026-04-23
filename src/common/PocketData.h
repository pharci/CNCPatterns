enum class PocketType {
    Circular = 1,
    Rectangular = 2
};

enum class InsertionType {
    Spiral = 1,
    Pendulum = 2,
    Vertical = 3
};

enum class CircularMachining {
    Planar = 1,
    Helical = 2
};

struct PocketParams {
    PocketType type;

    int ToolNumber;
    double Feed;
    double SpindleSpeed;

    double X;
    double Y;
    double Z;
    double Z1;
    double DZ;

    double radius;
    double length;
    double width;

    InsertionType insertion;
    double insertionR;
    double insertionH;
    double insertionAngle;

    CircularMachining machining;
};
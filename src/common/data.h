enum class PocketType {
    Circular,
    Rectangular
};

enum class InsertionType {
    Spiral,
    Pendulum,
    Vertical
};

enum class CircularMachining {
    Planar,
    Helical
};

struct PocketParams {
    PocketType type;

    double x;
    double y;
    double depth;

    double radius;
    double length;
    double width;

    InsertionType insertion;
    double insertionR;
    double insertionH;
    double insertionAngle;

    CircularMachining machining;
};
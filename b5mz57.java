public class masodikhazi {
    public static void main(String[] args) {
    Segment s = new Segment(3,3,6,6);
    //Point p = new Point(4,4);
    //Point p2 = new Point(4,3);
    //point p3 = new Point(1,1);
    s.line();

    System.out.println(s.orientation(p2));
  }
}

class Point {
  double _x,_y;
  public Point(double x, double y) {
    this._x = x;
    this._y = y;
  }
}

class Line {
  double _a, _b, _c;
  public Line(double a, double b, double c) {
    this._a = a;
    this._b = b;
    this._c = c;
  }
};



class Segment {
  double x1, y1, x2, y2;
  Line myLine;

  public Segment(double x1, double y1, double x2, double y2) {
    this.x1 = x1;
    this.y1 = y1;
    this.x2 = x2;
    this.y2 = y2;
  }

  Line line() {
    Point tempPoint = new Point(this.x2-this.x1,this.y2-this.y1);
    Line tempLine = new Line (tempPoint._y,-tempPoint._x,tempPoint._y * this.x1 - tempPoint._x * this.y1);
    this.myLine = tempLine;
    return tempLine;
  }

  boolean contains(Point p) {
    //y = mx + c alapjan
    double mx = -(this.myLine._a) / (this.myLine._b);
    double c = (this.myLine._c) / (this.myLine._b);

    boolean equalSlope = p._y == mx * p._x + c;
    boolean xInRange =  Math.min(x1,x2) <= p._x && p._x <= Math.max(x1, x2);
    boolean yInRange = Math.min(y1,y2) <= p._y  && p._y <= Math.max(y1, y2);

    return equalSlope && xInRange && yInRange ? true : false;
  }

  int orientation(Point p) {
    double res = (this.y2-this.y1) * (p._x-this.x2) - (p._y-this.y2) * (this.x2-this.x1);
    if(res == 0)
      return 0;
    if (res > 0)
      return 1;
    return -1;
  }

  boolean intersects(Segment s) {

    Point objectLineStartPoint = new Point(this.x1, this.y1);
    Point objectLineEndPoint = new Point(this.x2, this.y2);

    Point segmentLineStartPoint = new Point(s.x1, s.y1);
    Point segmentLineEndPoint = new Point(s.x2, s.y2);

    int objectStartPointOrientation = this.orientation(segmentLineStartPoint);
    int objectEndPointOrientation = this.orientation(segmentLineEndPoint);

    int segmentStartPointOrientation = s.orientation(objectLineStartPoint);
    int segmentEndPointOrientation = s.orientation(objectLineEndPoint);

    if((objectStartPointOrientation > objectEndPointOrientation || objectStartPointOrientation < objectEndPointOrientation) && (segmentStartPointOrientation > segmentEndPointOrientation || segmentStartPointOrientation < segmentEndPointOrientation))
      return true;
    if(objectStartPointOrientation == 0 && objectEndPointOrientation == 0 && segmentStartPointOrientation == 0 && segmentEndPointOrientation == 0 && this.contains(segmentLineStartPoint))
        return true;
    if(objectStartPointOrientation == 0 && objectEndPointOrientation == 0 && segmentStartPointOrientation == 0 && segmentEndPointOrientation == 0 && this.contains(segmentLineEndPoint))
        return true;
     if(objectStartPointOrientation == 0 && objectEndPointOrientation == 0 && segmentStartPointOrientation == 0 && segmentEndPointOrientation == 0 && s.contains(objectLineStartPoint))
        return true;
     if(objectStartPointOrientation == 0 && objectEndPointOrientation == 0 && segmentStartPointOrientation == 0 && segmentEndPointOrientation == 0 && s.contains(objectLineEndPoint))
        return true;
    return false;
  }
};
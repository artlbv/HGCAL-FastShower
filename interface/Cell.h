

#ifndef __HGCalSimulation_FastShower_Cell_h__
#define __HGCalSimulation_FastShower_Cell_h__

#include "TVectorD.h"

class Cell {
  // an polygonal cell

  public:
    static uint32_t id(uint16_t i, uint16_t j);

  private:
    Cell() {} // don't use default constructor


  public:
    // constructor for parametrized and full geometries
    // move position and vertices (the Cell object is the owner)
    Cell(TVectorD&&, std::vector<TVectorD>&&, double, int, int); 
    //Cell(const Cell&);
    //Cell& operator=(const Cell&);
    ~Cell() {};

    // getters
    const TVectorD& getPosition() const {return position_;}
    const std::vector<TVectorD>& getVertices() const {return vertices_;}
    double getOrientation() const {return orientation_;}
    int getIIndex() const {return i_index_;}
    int getJIndex() const {return j_index_;}
    uint32_t id() const {return id_;}
    bool isFullCell() const {return orientation_==90.;}
    bool isHalfCell() const {return int(orientation_)%60==0;}

  private:
    TVectorD position_; // centre position in absolute coordinates
    std::vector<TVectorD> vertices_; // vertices positions in absolute coordinates
    double orientation_; // orientation for halh cells
    // hopefully 16 bits are enough
    int16_t i_index_; // I index
    int16_t j_index_;  // J index
    // | j_index  | i_index |
    // |31 -----16|15 -----0|
    uint32_t id_; // identifier built from i and j indices
};

//struct CellComp {
  //bool operator() (const Cell* c1, const Cell* c2) const {
    //if (c1->getIIndex()!=c2->getIIndex()) return (c1->getIIndex()<c2->getIIndex());
    //else return (c1->getJIndex()<c2->getJIndex());
  //}
//};

#endif

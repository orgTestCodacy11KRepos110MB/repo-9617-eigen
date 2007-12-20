// This file is part of Eigen, a lightweight C++ template library
// for linear algebra. Eigen itself is part of the KDE project.
//
// Copyright (C) 2006-2007 Benoit Jacob <jacob@math.jussieu.fr>
//
// Eigen is free software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation; either version 2 or (at your option) any later version.
//
// Eigen is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along
// with Eigen; if not, write to the Free Software Foundation, Inc., 51
// Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. This exception does not invalidate any other reasons why a work
// based on this file might be covered by the GNU General Public License.

#ifndef EIGEN_COLUMN_H
#define EIGEN_COLUMN_H

template<typename MatrixType> class Column
  : public MatrixBase<typename MatrixType::Scalar, Column<MatrixType> >
{
  public:
    typedef typename MatrixType::Scalar Scalar;
    typedef typename MatrixType::Ref MatRef;
    friend class MatrixBase<Scalar, Column<MatrixType> >;
    
    Column(const MatRef& matrix, int col)
      : m_matrix(matrix), m_col(col)
    {
      assert(col >= 0 && col < matrix.cols());
    }
    
    Column(const Column& other)
      : m_matrix(other.m_matrix), m_col(other.m_col) {}
    
    EIGEN_INHERIT_ASSIGNMENT_OPERATORS(Column)
    
  private:
    static const int _RowsAtCompileTime = MatrixType::RowsAtCompileTime,
                     _ColsAtCompileTime = 1;
    const Column& _ref() const { return *this; }
    int _rows() const { return m_matrix.rows(); }
    int _cols() const { return 1; }
    
    Scalar& _coeffRef(int row, int)
    {
      return m_matrix.coeffRef(row, m_col);
    }
    
    Scalar _coeff(int row, int) const
    {
      return m_matrix.coeff(row, m_col);
    }
    
  protected:
    MatRef m_matrix;
    const int m_col;
};

/** \returns an expression of the \a i-th column of *this.
  * \sa row(int) */
template<typename Scalar, typename Derived>
Column<Derived>
MatrixBase<Scalar, Derived>::col(int i) const
{
  return Column<Derived>(static_cast<Derived*>(const_cast<MatrixBase*>(this))->ref(), i);
}

#endif // EIGEN_COLUMN_H

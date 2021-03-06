/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
#ifndef EDITPLUGIN_H
#define EDITPLUGIN_H

#include <common/interfaces.h>

class EditSelectPlugin : public QObject, public MeshEditInterface
{
    Q_OBJECT
    Q_INTERFACES(MeshEditInterface)


public:
    enum { SET_VERT_Q, SET_FACE_Q, SAVE_CURVATURE ,SET_FACE_Q2, SAVE_FACE_Q, 
		SET_FACE_Q3, SAVE_SEP_LABEL, SAVE_VERT_Q, SET_Q_PAPER} ;

    EditSelectPlugin(int mode);

    virtual ~EditSelectPlugin() {}

    static QString Info();
	QString filterName(FilterIDType filter) const;
    virtual bool StartEdit(MeshModel &/*m*/, GLArea * /*parent*/);
    virtual void EndEdit(MeshModel &/*m*/, GLArea * /*parent*/) ;
    virtual void Decorate(MeshModel &/*m*/, GLArea * /*parent*/);
    virtual void mousePressEvent(QMouseEvent *event, MeshModel &/*m*/, GLArea *);
    virtual void mouseMoveEvent(QMouseEvent *event, MeshModel &/*m*/, GLArea *);
    virtual void mouseReleaseEvent(QMouseEvent *event, MeshModel &/*m*/, GLArea *);
    virtual void keyReleaseEvent(QKeyEvent *, MeshModel &/*m*/, GLArea *);
    virtual void keyPressEvent(QKeyEvent *, MeshModel &/*m*/, GLArea *);
    
    int mode_;
private:
    void set_vert_q(MeshModel &m);
    void set_face_q(MeshModel &m,float per);
	void set_face_q(MeshModel &m); // set a proper color, used in paper
    void save_curvature(MeshModel &m);
	void save_face_q(MeshModel &m);
	void set_face_q3(MeshModel &m);
	void save_sep_label(MeshModel &m);
	void save_vert_q(MeshModel &m);
};

#endif

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/gl.h"

#include "ObjFrame.h"


using namespace ci;
using namespace ci::app;
using namespace std;



class ObjSequenceApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    std::vector<ObjFrameRef> mFrames;
};

void ObjSequenceApp::setup()
{
}

void ObjSequenceApp::mouseDown( MouseEvent event )
{
}

void ObjSequenceApp::update()
{
}

void ObjSequenceApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

//object loader
void ObjSequenceApp::loadObj( const DataSourceRef &dataSource )
{
    ObjLoader loader( dataSource );
    mMesh = TriMesh::create( loader );
    
    if( ! loader.getAvailableAttribs().count( geom::NORMAL ) )
        mMesh->recalculateNormals();
    
    mBatch = gl::Batch::create( *mMesh, mGlsl );
    
    mBoundingSphere = Sphere::calculateBoundingSphere( mMesh->getPositions<3>(), mMesh->getNumVertices() );
    mArcball.setSphere( mBoundingSphere );
}

CINDER_APP( ObjSequenceApp, RendererGl )

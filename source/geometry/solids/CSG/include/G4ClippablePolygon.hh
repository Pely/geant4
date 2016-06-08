//
// G4ClippablePolygon.hh
//
// Declaration of a utility class of a polycon that can be clipped
// by a voxel
//
// ----------------------------------------------------------
// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
#ifndef G4ClippablePolycon_hh
#define G4ClippablePolycon_hh

#include "globals.hh"
#include "geomdefs.hh"
#include "G4ThreeVector.hh"

class G4VoxelLimits;
class G4AffineTransform;

class G4AffineTransform;
class G4VoxelLimits;

#include <rw/tvordvec.h>
typedef RWTValOrderedVector<G4ThreeVector> G4ThreeVectorList;

class G4ClippablePolygon {
	public:
	G4ClippablePolygon() {;}
	virtual ~G4ClippablePolygon() {;}
	
	virtual void AddVertexInOrder( const G4ThreeVector vertex );
	virtual void ClearAllVertices();
	
	virtual void SetNormal( const G4ThreeVector &newNormal ) { normal = newNormal; }
	virtual const G4ThreeVector GetNormal() const { return normal; }
	
	virtual const G4bool Clip( const G4VoxelLimits &voxelLimit );

	virtual const G4bool PartialClip( const G4VoxelLimits &voxelLimit, const EAxis IgnoreMe );
	
	virtual void ClipAlongOneAxis( const G4VoxelLimits &voxelLimit, const EAxis axis );
	
	virtual const G4bool GetExtent( const EAxis axis, 
		    	                G4double &min, G4double &max ) const;
	virtual const G4ThreeVector *GetMinPoint( const EAxis axis ) const;
	virtual const G4ThreeVector *GetMaxPoint( const EAxis axis ) const;
			  
	virtual const G4int GetNumVertices() const { return vertices.entries(); }
	virtual const G4bool Empty() const { return vertices.entries()==0; }
	
	virtual const G4bool InFrontOf( const G4ClippablePolygon &other, EAxis axis ) const;
	virtual const G4bool BehindOf( const G4ClippablePolygon &other, EAxis axis ) const;
	virtual const G4bool GetPlanerExtent( const G4ThreeVector &pointOnPlane, 
					      const G4ThreeVector &planeNormal,
					      G4double &min, G4double &max ) const;
			      
	protected:
	G4ThreeVectorList vertices;
	G4ThreeVector normal;
	
	void ClipToSimpleLimits( G4ThreeVectorList& pPolygon,
				 G4ThreeVectorList& outputPolygon,
				 const G4VoxelLimits& pVoxelLimit  );

};

#endif
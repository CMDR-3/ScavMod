#pragma once

#include "OgrePrerequisites.h"

namespace Ogre
{
	/** Manages the organisation and rendering of a 'scene' i.e. a collection
	of objects and potentially world geometry.
@remarks
	This class defines the interface and the basic behaviour of a
	'Scene Manager'. A SceneManager organises the culling and rendering of
	the scene, in conjunction with the RenderQueue. This class is designed
	to be extended through subclassing in order to provide more specialised
	scene organisation structures for particular needs. The default
	SceneManager culls based on a hierarchy of node bounding boxes, other
	implementations can use an octree (@see OctreeSceneManager), a BSP
	tree (@see BspSceneManager), and many other options. New SceneManager
	implementations can be added at runtime by plugins, see
	SceneManagerEnumerator for the interfaces for adding new SceneManager
	types.
@par
	There is a distinction between 'objects' (which subclass MovableObject,
	and are movable, discrete objects in the world), and 'world geometry',
	which is large, generally static geometry. World geometry tends to
	influence the SceneManager organisational structure (e.g. lots of indoor
	static geometry might result in a spatial tree structure) and as such
	world geometry is generally tied to a given SceneManager implementation,
	whilst MovableObject instances can be used with any SceneManager.
	Subclasses are free to define world geometry however they please.
@par
	Multiple SceneManager instances can exist at one time, each one with
	a distinct scene. Which SceneManager is used to render a scene is
	dependent on the Camera, which will always call back the SceneManager
	which created it to render the scene.
	 */
	class SceneManager
	{
	public:
		/// Query type mask which will be used for world geometry @see SceneQuery
		static uint32 WORLD_GEOMETRY_TYPE_MASK;
		/// Query type mask which will be used for entities @see SceneQuery
		static uint32 ENTITY_TYPE_MASK;
		/// Query type mask which will be used for effects like billboardsets / particle systems @see SceneQuery
		static uint32 FX_TYPE_MASK;
		/// Query type mask which will be used for StaticGeometry  @see SceneQuery
		static uint32 STATICGEOMETRY_TYPE_MASK;
		/// Query type mask which will be used for lights  @see SceneQuery
		static uint32 LIGHT_TYPE_MASK;
		/// Query type mask which will be used for frusta and cameras @see SceneQuery
		static uint32 FRUSTUM_TYPE_MASK;
		/// User type mask limit
		static uint32 USER_TYPE_MASK_LIMIT;

	protected:

	public:
		
	};
}
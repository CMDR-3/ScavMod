#pragma once

#include "OgrePlatform.h"

#include "string"

namespace Ogre {
    // Define ogre version
#define OGRE_VERSION_MAJOR 1
#define OGRE_VERSION_MINOR 8
#define OGRE_VERSION_PATCH 1
#define OGRE_VERSION_SUFFIX ""
#define OGRE_VERSION_NAME "Byatis"

//#define OGRE_WCHAR_T_STRINGS
#define OGRE_COMPILER_MSVC 1
#define OGRE_COMPILER OGRE_COMPILER_MSVC
#define OGRE_COMP_VER 2000

#define OGRE_VERSION    ((OGRE_VERSION_MAJOR << 16) | (OGRE_VERSION_MINOR << 8) | OGRE_VERSION_PATCH)

// define the real number values to be used
// default to use 'float' unless precompiler option set
#if OGRE_DOUBLE_PRECISION == 1
    /** Software floating point type.
    @note Not valid as a pointer to GPU buffers / parameters
    */
    typedef double Real;
#else
    /** Software floating point type.
    @note Not valid as a pointer to GPU buffers / parameters
    */
    typedef float Real;
#endif

#if OGRE_COMPILER == OGRE_COMPILER_GNUC && OGRE_COMP_VER >= 310 && !defined(STLPORT)
#   if OGRE_COMP_VER >= 430
#       define HashMap ::std::tr1::unordered_map
#		define HashSet ::std::tr1::unordered_set
#    else
#       define HashMap ::__gnu_cxx::hash_map
#       define HashSet ::__gnu_cxx::hash_set
#    endif
#elif OGRE_COMPILER == OGRE_COMPILER_CLANG
#    if defined(_LIBCPP_VERSION)
#       define HashMap ::std::unordered_map
#       define HashSet ::std::unordered_set
#    else
#       define HashMap ::std::tr1::unordered_map
#       define HashSet ::std::tr1::unordered_set
#    endif
#else
#   if OGRE_COMPILER == OGRE_COMPILER_MSVC
#       if OGRE_COMP_VER >= 1600 // VC++ 10.0
#			define HashMap ::std::tr1::unordered_map
#           define HashSet ::std::tr1::unordered_set
#		elif OGRE_COMP_VER > 1300 && !defined(_STLP_MSVC)
#           define HashMap ::stdext::hash_map
#           define HashSet ::stdext::hash_set
#       else
#           define HashMap ::std::hash_map
#           define HashSet ::std::hash_set
#       endif
#   else
#       define HashMap ::std::hash_map
#       define HashSet ::std::hash_set
#   endif
#endif

#ifdef OGRE_WCHAR_T_STRINGS
    typedef std::wstring _StringBase;
#else
    typedef std::string _StringBase;
#endif

#ifdef OGRE_WCHAR_T_STRINGS
    typedef std::basic_stringstream<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > _StringStreamBase;
#else
    typedef std::basic_stringstream<char, std::char_traits<char>, std::allocator<char> > _StringStreamBase;
#endif

    typedef _StringBase String;
    typedef _StringStreamBase StringStream;
    typedef StringStream stringstream;

#define OGRE_DEFINE_STATIC_LOCAL(type, name, arguments) \
        static type& name = *new type arguments

    /** In order to avoid finger-aches :)
    */
    typedef unsigned char uchar;
    typedef unsigned short ushort;
    typedef unsigned int uint;
    typedef unsigned long ulong;

    // Useful threading defines

// Pre-declare classes
// Allows use of pointers in header files without including individual .h
// so decreases dependencies between files
    class Angle;
    class Animation;
    class AnimationState;
    class AnimationStateSet;
    class AnimationTrack;
    class Archive;
    class ArchiveFactory;
    class ArchiveManager;
    class AutoParamDataSource;
    class AxisAlignedBox;
    class AxisAlignedBoxSceneQuery;
    class Billboard;
    class BillboardChain;
    class BillboardSet;
    class Bone;
    class Camera;
    class Codec;
    class ColourValue;
    class ConfigDialog;
    template <typename T> class Controller;
    template <typename T> class ControllerFunction;
    class ControllerManager;
    template <typename T> class ControllerValue;
    class DefaultWorkQueue;
    class Degree;
    class DepthBuffer;
    class DynLib;
    class DynLibManager;
    class EdgeData;
    class EdgeListBuilder;
    class Entity;
    class ErrorDialog;
    class ExternalTextureSourceManager;
    class Factory;
    class Font;
    class FontPtr;
    class FontManager;
    struct FrameEvent;
    class FrameListener;
    class Frustum;
    class GpuProgram;
    class GpuProgramPtr;
    class GpuProgramManager;
    class GpuProgramUsage;
    class HardwareIndexBuffer;
    class HardwareOcclusionQuery;
    class HardwareVertexBuffer;
    class HardwarePixelBuffer;
    class HardwarePixelBufferSharedPtr;
    class HighLevelGpuProgram;
    class HighLevelGpuProgramPtr;
    class HighLevelGpuProgramManager;
    class HighLevelGpuProgramFactory;
    class IndexData;
    class InstanceBatch;
    class InstanceBatchHW;
    class InstanceBatchHW_VTF;
    class InstanceBatchShader;
    class InstanceBatchVTF;
    class InstanceManager;
    class InstancedEntity;
    class IntersectionSceneQuery;
    class IntersectionSceneQueryListener;
    class Image;
    class KeyFrame;
    class Light;
    class Log;
    class LogManager;
    class LodStrategy;
    class ManualResourceLoader;
    class ManualObject;
    class Material;
    class MaterialPtr;
    class MaterialManager;
    class Math;
    class Matrix3;
    class Matrix4;
    class MemoryManager;
    class Mesh;
    class MeshPtr;
    class MeshSerializer;
    class MeshSerializerImpl;
    class MeshManager;
    class MovableObject;
    class MovablePlane;
    class Node;
    class NodeAnimationTrack;
    class NodeKeyFrame;
    class NumericAnimationTrack;
    class NumericKeyFrame;
    class Overlay;
    class OverlayContainer;
    class OverlayElement;
    class OverlayElementFactory;
    class OverlayManager;
    class Particle;
    class ParticleAffector;
    class ParticleAffectorFactory;
    class ParticleEmitter;
    class ParticleEmitterFactory;
    class ParticleSystem;
    class ParticleSystemManager;
    class ParticleSystemRenderer;
    class ParticleSystemRendererFactory;
    class ParticleVisualData;
    class Pass;
    class PatchMesh;
    class PixelBox;
    class Plane;
    class PlaneBoundedVolume;
    class Plugin;
    class Pose;
    class ProgressiveMesh;
    class Profile;
    class Profiler;
    class Quaternion;
    class Radian;
    class Ray;
    class RaySceneQuery;
    class RaySceneQueryListener;
    class Renderable;
    class RenderPriorityGroup;
    class RenderQueue;
    class RenderQueueGroup;
    class RenderQueueInvocation;
    class RenderQueueInvocationSequence;
    class RenderQueueListener;
    class RenderObjectListener;
    class RenderSystem;
    class RenderSystemCapabilities;
    class RenderSystemCapabilitiesManager;
    class RenderSystemCapabilitiesSerializer;
    class RenderTarget;
    class RenderTargetListener;
    class RenderTexture;
    class MultiRenderTarget;
    class RenderWindow;
    class RenderOperation;
    class Resource;
    class ResourceBackgroundQueue;
    class ResourceGroupManager;
    class ResourceManager;
    class RibbonTrail;
    class Root;
    class SceneManager;
    class SceneManagerEnumerator;
    class SceneNode;
    class SceneQuery;
    class SceneQueryListener;
    class ScriptCompiler;
    class ScriptCompilerManager;
    class ScriptLoader;
    class Serializer;
    class ShadowCaster;
    class ShadowRenderable;
    class ShadowTextureManager;
    class SimpleRenderable;
    class SimpleSpline;
    class Skeleton;
    class SkeletonPtr;
    class SkeletonInstance;
    class SkeletonManager;
    class Sphere;
    class SphereSceneQuery;
    class StaticGeometry;
    class StreamSerialiser;
    class StringConverter;
    class StringInterface;
    class SubEntity;
    class SubMesh;
    class TagPoint;
    class Technique;
    class TempBlendedBufferInfo;
    class ExternalTextureSource;
    class TextureUnitState;
    class Texture;
    class TexturePtr;
    class TextureManager;
    class TransformKeyFrame;
    class Timer;
    class UserObjectBindings;
    class Vector2;
    class Vector3;
    class Vector4;
    class Viewport;
    class VertexAnimationTrack;
    class VertexBufferBinding;
    class VertexData;
    class VertexDeclaration;
    class VertexMorphKeyFrame;
    class WireBoundingBox;
    class WorkQueue;
    class Compositor;
    class CompositorManager;
    class CompositorChain;
    class CompositorInstance;
    class CompositorLogic;
    class CompositionTechnique;
    class CompositionPass;
    class CompositionTargetPass;
    class CustomCompositionPass;
}
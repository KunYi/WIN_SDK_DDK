; ==================================================================================================
; Title:      D3Engine.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm 3D Engine objects.
; ==================================================================================================


; The 3D model
;
; D3Object:
;
;           覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;          |                                                                        |
;          |       覧覧�      覧覧覧覧覧覧�           覧覧覧覧�         覧覧�       |
;          |      |     | /  |       C/I 1 |   \     | V0 | Vt |   \   |     |      |
;          |      | Tri | |  | C0    C/I 2 |    \    |    |    |   |   | Vec |      |
;          |      | ang | |  |       C/I 3 |     \   |    |    |   |   | tro |      |
;          |      | les | |   覧覧覧覧覧覧�       \  |  . | .  |   |   |  ns |      |
;          |      |     | |                          |  . | .  |   |   |     |      |
;          |      | Col |<        ...          覧覧  |  . | .  |    >  | Vec |      |
;          |      | lec | |                          |    |    |   |   | ton |      |
;          |      | tio | |   覧覧覧覧覧覧�       /  |    |    |   |   | Col |      |
;          |      |  n  | |  |       C/I 1 |     /   |    |    |   |   | lec |      |
;          |      |     | |  | C0    C/I 2 |    /    |    |    |   |   | tio |      |
;          |      |     | \  |       C/I 3 |   /     |    |    |   /   |  n  |      |
;          |       覧覧�      覧覧覧覧覧覧�           覧覧覧覧�         覧覧�       |
;          |    Collection      D3Triangle            D3Vectron       D3Vectron-    |
;          |                                                          Collection    |
;           覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;
;
; D3Camera:
;
;           覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;          |                                                                        |
;          |    覧覧�      覧覧覧覧        覧覧覧覧覧覧覧覧覧覧覧覧�        覧覧�   |
;          |   |     | /  | Vector |      |ObjIndex|Ptr.Triag.|Dist.|  \   |     |  |
;          |   | Obj | |   覧覧覧覧       |        |          |     |  |   | Sor |  |
;          |   | Pro | |                  |        |          |     |  |   | ted |  |
;          |   | js  | |   覧覧覧覧       |    .   |     .    |  .  |  |   | Tri |  |
;          |   |     | |  | Vector |      |    .   |     .    |  .  |  |   | dat |  |
;          |   | Dat |<    覧覧覧覧       |    .   |     .    |  .  |   >  |  a  |  |
;          |   | aCo | |                  |        |          |     |  |   | Sor |  |
;          |   | lle | |     ...          |        |          |     |  |   | ted |  |
;          |   | cti | |                  |        |          |     |  |   | Dat |  |
;          |   |  on | |   覧覧覧覧       |        |          |     |  |   | aCo |  |
;          |   |     | \  | Vector |      |        |          |     |  /   | ll. |  |
;          |    覧覧�      覧覧覧覧        覧覧覧覧覧覧覧覧覧覧覧覧�        覧覧�   |
;          |    Data-      D3Vector                  TriData             SortedData-|
;          | Collection                                                  Collection |
;           覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;
;
; D3Scene:
;
;           覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;          |                                    |
;          |    覧覧覧覧覧�      覧覧覧覧覧     |
;          |   |           | /  | D3Object |    |             Conventions
;          |   |           | |   覧覧覧覧覧     |
;          |   | D3Objects |<       ...         |
;          |   |           | |   覧覧覧覧覧     |                +覧覧覧 x
;          |   |           | \  | D3Object |    |              / |
;          |    覧覧覧覧覧�      覧覧覧覧覧     |             /  |
;          |                                    |            z   |
;          |    覧覧覧覧覧�      覧覧覧覧覧     |                y
;          |   |           | /  | D3Camera |    |
;          |   |           | |   覧覧覧覧覧     |
;          |   | D3Cameras |<       ...         |             Angles
;          |   |           | |   覧覧覧覧覧     |             x -> y (+)
;          |   |           | \  | D3Camera |    |             y -> z (+)
;          |    覧覧覧覧覧�      覧覧覧覧覧     |             z -> x (+)
;          |                                    |
;          |    覧覧覧覧覧�      覧覧覧覧覧     |
;          |   |           | /  | D3Light  |    |
;          |   |           | |   覧覧覧覧覧     |
;          |   | D3Lights  |<       ...         |
;          |   |           | |   覧覧覧覧覧     |
;          |   |           | \  | D3Light  |    |
;          |    覧覧覧覧覧�      覧覧覧覧覧     |
;          |                                    |
;           覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;


; ==================================================================================================
;    Structure definitions
; ==================================================================================================

TriData struc 4
  dObjectIndex  DWORD       ?
  pTriangle     POINTER     ?
  r4Distance    REAL4       ?
TriData ends
PTriData typedef ptr TriData

TriVertex struc 4
  sdX           SDWORD      ?
  sdY           SDWORD      ?
  wBlue         WORD        ?                   ;Valid range 0000h to FF00h
  wGreen        WORD        ?                   ;Valid range 0000h to FF00h
  wRed          WORD        ?                   ;Valid range 0000h to FF00h
  wAlpha        WORD        ?                   ;Valid range 0000h to FF00h
TriVertex ends
PTriVertex typedef TriVertex

GradientTriangle struc 4
  dIndex1       DWORD       ?
  dIndex2       DWORD       ?
  dIndex3       DWORD       ?
GradientTriangle ends
PGradientTriangle typedef ptr GradientTriangle

D3Vector struc 4
  r4X           REAL4       0.0                 ;X coordinate
  r4Y           REAL4       0.0                 ;Y coordinate
  r4Z           REAL4       0.0                 ;Z coordinate
D3Vector ends
PD3Vector typedef ptr D3Vector

D3Vectron struc 4
  Vo            D3Vector    { 0.0, 0.0, 0.0}    ;Original vector
  Vt            D3Vector    { 0.0, 0.0, 0.0}    ;Transformed vector
D3Vectron ends
PD3Vectron typedef ptr D3Vectron

; ==================================================================================================
;    D3Math protos
; ==================================================================================================

RotateX                     proto :PD3Vectron, :XWORD, :XWORD
RotateY                     proto :PD3Vectron, :XWORD, :XWORD
RotateZ                     proto :PD3Vectron, :XWORD, :XWORD
Translate                   proto :PD3Vectron, :XWORD, :XWORD
MoveVo2Vt                   proto :PD3Vectron, :XWORD, :XWORD
VectorCrossVector           proto :PD3Vector, :PD3Vector, :PD3Vector
VectorDotVector             proto :PD3Vector, :PD3Vector
VectorCrossVectorDotVector  proto :PD3Vector, :PD3Vector, :PD3Vector
VectorAddVector             proto :PD3Vector, :PD3Vector, :PD3Vector
VectorSubVector             proto :PD3Vector, :PD3Vector, :PD3Vector
VectorModulus               proto :PD3Vector
VectorScale                 proto :PD3Vector, :PD3Vector, :PD3Vector
VectorNormalize             proto :PD3Vector, :PD3Vector


; ==================================================================================================
;    Object definitions
; ==================================================================================================

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:   D3VectronCollection
; Purpose:  Implementation of D3Engine D3VectronCollection object.

Object D3VectronCollection, D3VectronCollectionID, DataCollection
  VirtualMethod   Append,           PD3Vector                     ;-> D3Vector
  RedefineMethod  GetItem,          $ObjPtr(Stream), PDESER_INFO  ;-> Stream, -> PDESER_INFO
  RedefineMethod  PutItem,          $ObjPtr(Stream), PD3Vectron   ;-> Stream, -> D3Vectron
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:   D3Light
; Purpose:  Implementation of D3Engine D3Light object.

Object D3Light, D3LightID, Streamable
  VirtualMethod   Colorize,         $ObjPtr(Collection), XWORD    ;-> D3Object collection
  RedefineMethod  Load,             $ObjPtr(Stream), PDESER_INFO  ;-> Stream, -> DESER_INFO
  VirtualMethod   Move,             POINTER                       ;-> Origin displacement
  RedefineMethod  Store,            $ObjPtr(Stream)               ;-> Stream

  DefineVariable  Origin,           D3Vector,   { 0.0, 0.0, 0.0}  ;Displacement vector
  DefineVariable  r4Intensity,      REAL4,      100.0
  DefineVariable  dColor,           DWORD,      $RGB( 255, 255, 255)
  DefineVariable  dFlags,           DWORD,      0
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:   D3Triangle
; Purpose:  Implementation of D3Engine D3Triangle object.

Object D3Triangle, D3TriangleID, Streamable
  VirtualMethod   Clone,            POINTER, XWORD
  VirtualMethod   Colorize,         $ObjPtr(D3Light), XWORD       ;-> D3Light
  VirtualMethod   Draw,             HDC, POINTER                  ;hDC, -> BufferDataColl
  RedefineMethod  Load,             $ObjPtr(Stream), PDESER_INFO  ;-> Stream, -> DESER_INFO
  RedefineMethod  Store,            $ObjPtr(Stream)               ;-> Stream

  DefineVariable  bTransparency,    BYTE,       0                 ;
  DefineVariable  bEmisivity,       BYTE,       0                 ;
  DefineVariable  bReflectivity,    BYTE,       0                 ;
  DefineVariable  bBrillance,       BYTE,       0                 ;
  DefineVariable  dIndex1,          DWORD,      0                 ;P1 Index into Vectron collection
  DefineVariable  dIndex2,          DWORD,      0                 ;P2 Index into Vectron collection
  DefineVariable  dIndex3,          DWORD,      0                 ;P3 Index into Vectron collection
  DefineVariable  SrcColor,         RGBQUAD,    { 0, 0, 0, 0}     ;Original RGB Color
  DefineVariable  OutColor1,        RGBQUAD,    { 0, 0, 0, 0}     ;P1 Output corner color
  DefineVariable  OutColor2,        RGBQUAD,    { 0, 0, 0, 0}     ;P2 Output corner color
  DefineVariable  OutColor3,        RGBQUAD,    { 0, 0, 0, 0}     ;P3 Output corner color
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:   D3Camera
; Purpose:  Implementation of D3Engine D3Camera object.

Object D3Camera, D3CameraID, Streamable
  VirtualMethod   Clear,            POINTER, XWORD
  VirtualMethod   Colorize,         $ObjPtr(D3Light), XWORD       ;-> D3Light
  RedefineMethod  Deserialize,      PDESER_INFO
  RedefineMethod  Done
  VirtualMethod   Draw,             HDC, DWORD                    ;DC HANDLE, Speed flag
  RedefineMethod  Init,             POINTER                       ;-> Owner
  RedefineMethod  Load,             $ObjPtr(Stream), PDESER_INFO  ;-> Stream, -> DESER_INFO
  VirtualMethod   Move,             PD3Vector, PD3Vector          ;-> Rotation, -> Displ.
  VirtualMethod   Project,          $ObjPtr(Collection), XWORD    ;-> D3Object collection
  RedefineMethod  Store,            $ObjPtr(Stream)               ;-> Stream

  DefineVariable  pSortedTriData,   $ObjPtr(SortedDataCollection),  NULL  ;Collection of TriData
  DefineVariable  pObjectProjs,     $ObjPtr(DataCollection),        NULL  ;Collection of POINT

  DefineVariable  Displacement,     D3Vector,   { 0.0, 0.0, 0.0}  ;Displacement vector
  DefineVariable  Orientation,      D3Vector,   { 0.0, 0.0, 0.0}  ;Orientation vector
  DefineVariable  VectronX,         D3Vectron,  {{1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}}
  DefineVariable  VectronY,         D3Vectron,  {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}
  DefineVariable  VectronZ,         D3Vectron,  {{0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}}
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:   D3Object
; Purpose:  Implementation of D3Engine D3Object object.

Object D3Object, D3ObjectID, Streamable
  VirtualMethod   AddPoint,         PD3Vector, DWORD              ;1x -> Vector, RGB
  VirtualMethod   AddLine,          PD3Vector, PD3Vector, DWORD   ;2x -> Vector, RGB
  VirtualMethod   AddObject,        POINTER                       ;-> D3Object
  VirtualMethod   AddRectangle,     PD3Vector, PD3Vector, PD3Vector, PD3Vector, DWORD ;4x -> Vec, RGB
  VirtualMethod   AddTriangle,      PD3Vector, PD3Vector, PD3Vector, DWORD  ;3x -> Vector, RGB
  RedefineMethod  Deserialize,      PDESER_INFO
  RedefineMethod  Done
  VirtualMethod   InfoAddTriCount,  POINTER, XWORD
  RedefineMethod  Init,             POINTER                       ;-> Owner
  RedefineMethod  Load,             $ObjPtr(Stream), PDESER_INFO  ;-> Stream, -> DESER_INFO
  VirtualMethod   Move,             PD3Vector, PD3Vector          ;-> Rotation, -> Displ.
  VirtualMethod   Project,          $ObjPtr(D3Camera), XWORD
  RedefineMethod  Store,            $ObjPtr(Stream)               ;-> Stream

  DefineVariable  pTriangles,       $ObjPtr(Collection),          NULL
  DefineVariable  pVectrons,        $ObjPtr(D3VectronCollection), NULL
  DefineVariable  dFlags,           DWORD,                  0     ;Visible, etc.
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:   D3Scene
; Purpose:  Implementation of D3Engine D3Scene object.

Object D3Scene, D3SceneID, Streamable
  VirtualMethod   Clear
  VirtualMethod   Colorize
  VirtualMethod   CreateBox,        POINTER, POINTER, POINTER, DWORD  ;-> WxHxD, RGB
  VirtualMethod   CreateGeoSphere,  DWORD, DWORD, REAL4, DWORD        ;Merid., Para., Rad., RGB
  RedefineMethod  Done
  RedefineMethod  Deserialize,      PDESER_INFO
  VirtualMethod   DestroyCamera,    $ObjPtr(D3Camera)
  VirtualMethod   DestroyLight,     $ObjPtr(D3Light)
  VirtualMethod   DestroyObject,    $ObjPtr(D3Object)
  VirtualMethod   InfoTriCount
  RedefineMethod  Init,             POINTER                           ;-> Owner
  RedefineMethod  Load,             $ObjPtr(Stream), PDESER_INFO      ;-> Stream, -> DESER_INFO
  VirtualMethod   NewCamera
  VirtualMethod   NewLight
  VirtualMethod   NewObject
  VirtualMethod   Project
  RedefineMethod  Store,            $ObjPtr(Stream)                   ;-> Stream

  DefineVariable  pObjects,         $ObjPtr(Collection),    NULL
  DefineVariable  pCameras,         $ObjPtr(Collection),    NULL
  DefineVariable  pLights,          $ObjPtr(Collection),    NULL
ObjectEnd



; ==================================================================================================

if IMPLEMENT

% include &ObjPath&D3Math.inc

% include &ObjPath&D3VectronCollection.inc
% include &ObjPath&D3Triangle.inc
% include &ObjPath&D3Object.inc
% include &ObjPath&D3Light.inc
% include &ObjPath&D3Camera.inc
% include &ObjPath&D3Scene.inc

endif

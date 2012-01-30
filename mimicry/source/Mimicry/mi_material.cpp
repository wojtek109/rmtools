#include "mi_include_unity.h"

#ifdef MI_IN_UNITY_FILE

#include "mi_include_scene.h"

mCMaterial::~mCMaterial( void )
{
}

mCMaterial::mCMaterial( mCString const & a_strName ) :
    mCMaterialBase( a_strName )
{
    for ( MIUInt u = EMapType_Count; u--; m_arrMaps[ u ] = 0 );
}

mCMaterial::mCMaterial( mCMaterial const & a_matSource ) :
    mCMaterialBase( a_matSource )
{
    for ( MIUInt u = EMapType_Count; u--; m_arrMaps[ u ] = a_matSource.m_arrMaps[ u ] );
}

mCMaterial::mCMaterial( void )
{
    for ( MIUInt u = EMapType_Count; u--; m_arrMaps[ u ] = 0 );
}

mCMaterial & mCMaterial::operator = ( mCMaterial const & a_matSource )
{
    mCMaterial matCopy( a_matSource );
    Swap( matCopy );
    return *this;
}

mCMaterial * mCMaterial::Clone( void )
{
    return new mCMaterial( *this );
}

mCTexMap const * mCMaterial::GetTextureMapAt( EMapType a_enuMapType ) const
{
    if ( a_enuMapType >= EMapType_Count )
        return 0;
    return m_arrMaps[ a_enuMapType ];
}

void mCMaterial::SetTextureMapAt( EMapType a_enuMapType, mCTexMap const & a_tmapSource )
{
    if ( a_enuMapType >= EMapType_Count )
        *m_arrMaps[ a_enuMapType ] = a_tmapSource;
}

void mCMaterial::Swap( mCMaterial & a_matOther )
{
    mCMaterialBase::Swap( a_matOther );
    for ( MIUInt u = EMapType_Count; u--; )
        g_swap( m_arrMaps[ u ], a_matOther.m_arrMaps[ u ] );
}

#endif
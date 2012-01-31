#include "mi_include_unity.h"

#ifdef MI_IN_UNITY_FILE

#include "mi_include_scene.h"

mCMaterialBase::~mCMaterialBase( void )
{
}

mCMaterialBase::mCMaterialBase( mCString const & a_strName ) :
    m_strName( a_strName )
{
}

mCMaterialBase::mCMaterialBase( mCMaterialBase const & a_matSource ) :
    m_strName( a_matSource.m_strName )
{
}

mCMaterialBase::mCMaterialBase( void )
{
    static MIUInt s_uCounter = 0;
    m_strName.Format( "Material #%u", ++s_uCounter );
}

mCMaterialBase & mCMaterialBase::operator = ( mCMaterialBase const & a_matSource )
{
    m_strName = a_matSource.m_strName;
    return *this;
}

mCString const & mCMaterialBase::GetName( void ) const
{
    return m_strName;
}

void mCMaterialBase::SetName( mCString const & a_strName )
{
    m_strName = a_strName;
}

void mCMaterialBase::Swap( mCMaterialBase & a_matOther )
{
    m_strName.Swap( a_matOther.m_strName );
}

#endif
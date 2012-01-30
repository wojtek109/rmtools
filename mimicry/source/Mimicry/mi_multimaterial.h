#ifndef MI_MULTIMATERIAL_H_INCLUDED
#define MI_MULTIMATERIAL_H_INCLUDED

class mCMultiMaterial :
    public mCMaterialBase
{
public:
   virtual ~mCMultiMaterial( void );
public:
    mCMultiMaterial( mCString const & a_strName );
    mCMultiMaterial( mCMultiMaterial const & a_matSource );
    mCMultiMaterial( void );
public:
    mCMultiMaterial &  operator =  ( mCMultiMaterial const & a_matSource );
    mCMaterial &       operator [] ( MIUInt a_uIndex );
    mCMaterial const & operator [] ( MIUInt a_uIndex ) const;
public:
    virtual mCMultiMaterial * Clone( void );
public:
    mTArray< mCMaterial > &       AccessSubMaterials( void );
    mTArray< mCMaterial > const & GetSubMaterials( void ) const;
    void                          Swap( mCMultiMaterial & a_matOther );
private:
    mTArray< mCMaterial > m_arrSubMaterials;
};

#endif
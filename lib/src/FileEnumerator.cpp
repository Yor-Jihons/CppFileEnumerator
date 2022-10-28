#include"FileEnumerator.h"
#include<memory>

namespace CppFileEnumerators{
    FileEnumerator::FileEnumerator( const std::wstring &target ) : m_targetPath(target),m_hFind(INVALID_HANDLE_VALUE){

    }

    FileEnumerator::~FileEnumerator(){
        if( this->m_hFind != nullptr ){
            this->Close();
        }
    }

    EnumResultTuple FileEnumerator::FindFirst( void ){
        WIN32_FIND_DATAW fd;
        m_hFind = FindFirstFileW( const_cast<wchar_t*>(m_targetPath.c_str()), &fd );
        if( m_hFind == INVALID_HANDLE_VALUE ) return std::make_tuple( false, std::move(nullptr) );
    return std::make_tuple( true, std::move( std::move( EnumResult::Create( fd ) ) ) );
    }

    EnumResultTuple FileEnumerator::FindNext( void ){
        WIN32_FIND_DATAW fd;
        BOOL bRes = FindNextFileW( this->m_hFind, &fd );
        if( bRes == 0 ) return std::make_tuple( false, std::move(nullptr) );
    return std::make_tuple( true, std::move( std::move( EnumResult::Create( fd ) ) ) );
    }

    bool FileEnumerator::Close( void ){
        if( this->m_hFind == nullptr ) return true;
        BOOL bRes = FindClose( this->m_hFind );
        if( bRes != 0 ) this->m_hFind = nullptr;
    return bRes;
    }
}

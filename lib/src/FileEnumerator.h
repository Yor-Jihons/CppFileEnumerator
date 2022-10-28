#ifndef YOR_OBJECTIVEFILEENUMCPP_OBJECTTIVEFILEENUM_H
#define YOR_OBJECTIVEFILEENUMCPP_OBJECTTIVEFILEENUM_H

#include<string>
#include<windows.h>
#include<memory>
#include"EnumResult.h"

#define UNICODE

namespace CppFileEnumerators{
    using EnumResultTuple = std::tuple<bool, std::unique_ptr<CppFileEnumerators::EnumResult>>;
    class FileEnumerator{
        public:
            FileEnumerator( const std::wstring &target );
            ~FileEnumerator();

            EnumResultTuple FindFirst( void );
            EnumResultTuple FindNext( void );

            bool Close( void );
        private:
            std::wstring m_dirPath;
            std::wstring m_targetPath;
            std::wstring m_origCurDir;
            HANDLE m_hFind;
    };
}

#endif

//!
//! @file Pl/U32String.cpp
//! @author Luk2010
//! @date 2024/01/26
//! @copyright Atlanti's Corp(r) 2024
//!

#include "Pl/U32String.h"

namespace Pl
{
    U32String::U32String(const char* cStr)
    {
        // Convert UTF-8 string to UTF-32 and store in mBuffer
        if (cStr == nullptr)
            return; // Or handle the case according to your requirements
        
        // Calculate the length of the UTF-8 string
        size_t len = strlen(cStr);
        
        // Iterate over the UTF-8 string and convert each character to UTF-32
        for (size_t i = 0; i < len; ) 
        {
            U32Char codepoint;
            unsigned char byte1 = static_cast<unsigned char>(cStr[i]);
            
            if (byte1 <= 0x7F) 
            {
                // Single-byte UTF-8 character
                codepoint = byte1;
                ++i;
            } 
            else if (byte1 >= 0xC0 && byte1 <= 0xDF && i + 1 < len)
            {
                // Two-byte UTF-8 character
                unsigned char byte2 = static_cast<unsigned char>(cStr[i + 1]);
                codepoint = ((byte1 & 0x1F) << 6) | (byte2 & 0x3F);
                i += 2;
            } 
            else if (byte1 >= 0xE0 && byte1 <= 0xEF && i + 2 < len)
            {
                // Three-byte UTF-8 character
                unsigned char byte2 = static_cast<unsigned char>(cStr[i + 1]);
                unsigned char byte3 = static_cast<unsigned char>(cStr[i + 2]);
                codepoint = ((byte1 & 0x0F) << 12) | ((byte2 & 0x3F) << 6) | (byte3 & 0x3F);
                i += 3;
            } 
            else if (byte1 >= 0xF0 && byte1 <= 0xF7 && i + 3 < len)
            {
                // Four-byte UTF-8 character
                unsigned char byte2 = static_cast<unsigned char>(cStr[i + 1]);
                unsigned char byte3 = static_cast<unsigned char>(cStr[i + 2]);
                unsigned char byte4 = static_cast<unsigned char>(cStr[i + 3]);
                codepoint = ((byte1 & 0x07) << 18) | ((byte2 & 0x3F) << 12) | ((byte3 & 0x3F) << 6) | (byte4 & 0x3F);
                i += 4;
            } 
            else
                // Invalid UTF-8 encoding
                // Handle the error according to your requirements
                return;
            
            // Store the UTF-32 character in mBuffer
            mBuffer.push_back(codepoint);
        }
    }
    
    size_t U32String::length() const
    {
        return mBuffer.size();
    }
    
    size_t U32String::size() const
    {
        return mBuffer.size() * sizeof(U32Char);
    }
    
    U32Char* U32String::data()
    {
        return mBuffer.data();
    }
    
    const U32Char* U32String::data() const
    {
        return mBuffer.data();
    }
    
    size_t U32String::findFirst(const U32String& rhs) const
    {
        // If either string is empty, return std::string::npos
        if (mBuffer.empty() || rhs.mBuffer.empty())
            return std::string::npos;
        
        // If the substring is longer than the string, return std::string::npos
        if (rhs.mBuffer.size() > mBuffer.size())
            return std::string::npos;
        
        // Iterate through the string to find the first occurrence of the substring
        for (size_t i = 0; i <= mBuffer.size() - rhs.mBuffer.size(); ++i) 
        {
            // Check if the substring matches the part of the string starting from index i
            bool found = true;
            for (size_t j = 0; j < rhs.mBuffer.size(); ++j) 
            {
                if (mBuffer[i + j] != rhs.mBuffer[j]) 
                {
                    found = false;
                    break;
                }
            }
            // If the substring is found, return the starting index
            if (found)
                return i;
        }
        
        // If the substring is not found, return std::string::npos
        return std::string::npos;
    }
    
    size_t U32String::findLast(const U32String& rhs) const
    {
        // If either string is empty, return std::string::npos
        if (mBuffer.empty() || rhs.mBuffer.empty())
            return std::string::npos;
        
        // If the substring is longer than the string, return std::string::npos
        if (rhs.mBuffer.size() > mBuffer.size())
            return std::string::npos;
        
        // Iterate through the string to find the last occurrence of the substring
        for (size_t i = mBuffer.size() - rhs.mBuffer.size(); i > 0; --i) 
        {
            // Check if the substring matches the part of the string starting from index i
            bool found = true;
            for (size_t j = 0; j < rhs.mBuffer.size(); ++j) 
            {
                if (mBuffer[i + j] != rhs.mBuffer[j]) 
                {
                    found = false;
                    break;
                }
            }
            // If the substring is found, return the starting index
            if (found)
                return i;
        }
        
        // If the substring is not found, return std::string::npos
        return std::string::npos;
    }
    
    size_t U32String::findNext(size_t from, const U32String& rhs) const
    {
        // If either string is empty, return std::string::npos
        if (mBuffer.empty() || rhs.mBuffer.empty())
            return std::string::npos;
        
        // If the substring is longer than the string, return std::string::npos
        if (rhs.mBuffer.size() > mBuffer.size())
            return std::string::npos;
        
        // Check if the starting position is valid
        if (from >= mBuffer.size())
            return std::string::npos;
        
        // Iterate through the string starting from the specified position to find the next occurrence of the substring
        for (size_t i = from; i <= mBuffer.size() - rhs.mBuffer.size(); ++i) 
        {
            // Check if the substring matches the part of the string starting from index i
            bool found = true;
            for (size_t j = 0; j < rhs.mBuffer.size(); ++j) 
            {
                if (mBuffer[i + j] != rhs.mBuffer[j]) 
                {
                    found = false;
                    break;
                }
            }
            // If the substring is found, return the starting index
            if (found)
                return i;
        }
        
        // If the substring is not found, return std::string::npos
        return std::string::npos;
    }
    
    void U32String::insert(size_t index, const U32String& str)
    {
        if (index > mBuffer.size())
            return;
        
        mBuffer.insert(mBuffer.begin() + index, str.mBuffer.begin(), str.mBuffer.end());
    }
    
    void U32String::append(const U32String& rhs)
    {
        insert(mBuffer.size(), rhs);
    }
    
    void U32String::prepend(const U32String& rhs)
    {
       insert(0, rhs);
    }
    
    void U32String::erase(size_t index, size_t count)
    {
        mBuffer.erase(mBuffer.begin() + index, mBuffer.begin() + count);
    }
    
    std::string U32String::utf8() const
    {
        std::stringstream ss;
        
        ss << *this;
        
        return ss.str();
    }
    
    std::ostream& operator << (std::ostream& os, const U32String& str)
    {
        // Iterate through each UTF-32 character in the U32String
        for (const U32Char& ch : str.mBuffer) {
            // Convert UTF-32 to UTF-8 and stream each byte
            if (ch <= 0x7F) {
                // Single-byte UTF-8 character
                os << static_cast<char>(ch);
            } else if (ch <= 0x7FF) {
                // Two-byte UTF-8 character
                os << static_cast<char>((ch >> 6) | 0xC0);
                os << static_cast<char>((ch & 0x3F) | 0x80);
            } else if (ch <= 0xFFFF) {
                // Three-byte UTF-8 character
                os << static_cast<char>((ch >> 12) | 0xE0);
                os << static_cast<char>(((ch >> 6) & 0x3F) | 0x80);
                os << static_cast<char>((ch & 0x3F) | 0x80);
            } else {
                // Four-byte UTF-8 character
                os << static_cast<char>((ch >> 18) | 0xF0);
                os << static_cast<char>(((ch >> 12) & 0x3F) | 0x80);
                os << static_cast<char>(((ch >> 6) & 0x3F) | 0x80);
                os << static_cast<char>((ch & 0x3F) | 0x80);
            }
        }
        return os;
    }

}

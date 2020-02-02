/////////////////////////////////////////////////
///
///  Lightweight JSON-based config library
///  https://github.com/d2d-systems/json-config
///  Licensed under the BSD-3-Clause License <https://opensource.org/licenses/BSD-3-Clause>.
///  SPDX-License-Identifier: BSD-3-Clause
///  Copyright (c) 2020, d2d-systems
///  All rights reserved.
///
///  Redistribution and use in source and binary forms, with or without
///  modification, are permitted provided that the following conditions are met:
///
///  1. Redistributions of source code must retain the above copyright notice, this
///  list of conditions and the following disclaimer.
///
///  2. Redistributions in binary form must reproduce the above copyright notice,
///  this list of conditions and the following disclaimer in the documentation
///  and/or other materials provided with the distribution.
///
///  3. Neither the name of the copyright holder nor the names of its
///  contributors may be used to endorse or promote products derived from
///  this software without specific prior written permission.
///
///  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
///  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
///  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
///  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
///  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
///  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
///  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
///  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
///  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
///  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
///
/////////////////////////////////////////////////
#pragma once

#include <nlohmann/json.hpp>

#include <filesystem>
#include <fstream>
#include <memory>
#include <optional>


namespace JSONConfig
{
using JSON = nlohmann::json;

class Config final
{
public:
    ~Config() = default;
    Config()  = default;

    Config( const Config & ) = default;
    Config( Config && )      = default;

    explicit Config( const std::filesystem::path &configFile )
    {
        try
        {
            std::ifstream configStream( configFile );
            configStream >> *m_Data;
        }
        catch( ... )
        {
        }
    }

    Config &operator=( const Config & ) = default;
    Config &operator=( Config && ) = default;

    template< typename T >
    operator std::optional< T >() const
    {
        try
        {
            return std::make_optional( m_Data->at( m_Path ).get< T >() );
        }
        catch( ... )
        {
            return std::nullopt;
        }
    }

    template< typename T >
    Config
    operator/( const T &key ) const
    {
        Config retValue {self()};
        retValue.m_Path /= key;
        return retValue;
    }

    template< typename T >
    Config
    operator[]( const T &key ) const
    {
        return self() / key;
    }

    template< typename T >
    T
    operator|( const T &defaultValue ) const
    {
        return  std::optional<T>{self()}.value_or(defaultValue);
    }

    auto
    cbegin() const noexcept
    {
        try
        {
            return m_Data->at( m_Path ).cbegin();
        }
        catch( ... )
        {
            return m_Data->cend();
        }
    }

    auto
    cend() const noexcept
    {
        try
        {
            return m_Data->at( m_Path ).cend();
        }
        catch( ... )
        {
            return m_Data->cend();
        }
    }

    auto
    begin() const noexcept
    {
        return cbegin();
    }

    auto
    end() const noexcept
    {
        return cend();
    }


    auto
    crbegin() const noexcept
    {
        try
        {
            return m_Data->at( m_Path ).crbegin();
        }
        catch( ... )
        {
            return m_Data->crend();
        }
    }

    auto
    crend() const noexcept
    {
        try
        {
            return m_Data->at( m_Path ).crend();
        }
        catch( ... )
        {
            return m_Data->crend();
        }
    }

    auto
    rbegin() const noexcept
    {
        return crbegin();
    }

    auto
    rend() const noexcept
    {
        return crend();
    }

private:
    const Config &
    self() const
    {
        return ( *this );
    }

    std::shared_ptr< JSON > m_Data {std::make_shared< JSON >()};
    JSON::json_pointer      m_Path {""_json_pointer};
};
}  // namespace JSONConfig

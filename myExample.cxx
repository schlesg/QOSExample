

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from myExample.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "myExample.hpp"
#include "myExamplePlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- myStruct: 

myStruct::myStruct() :
    m_myLong_ (0)  {
}   

myStruct::myStruct (
    int32_t myLong)
    :
        m_myLong_( myLong ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
myStruct::myStruct(myStruct&& other_) OMG_NOEXCEPT  :m_myLong_ (std::move(other_.m_myLong_))
{
} 

myStruct& myStruct::operator=(myStruct&&  other_) OMG_NOEXCEPT {
    myStruct tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void myStruct::swap(myStruct& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_myLong_, other_.m_myLong_);
}  

bool myStruct::operator == (const myStruct& other_) const {
    if (m_myLong_ != other_.m_myLong_) {
        return false;
    }
    return true;
}
bool myStruct::operator != (const myStruct& other_) const {
    return !this->operator ==(other_);
}

// --- Getters and Setters: -------------------------------------------------
int32_t& myStruct::myLong() OMG_NOEXCEPT {
    return m_myLong_;
}

const int32_t& myStruct::myLong() const OMG_NOEXCEPT {
    return m_myLong_;
}

void myStruct::myLong(int32_t value) {
    m_myLong_ = value;
}

std::ostream& operator << (std::ostream& o,const myStruct& sample)
{
    rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "myLong: " << sample.myLong() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        template<>
        struct native_type_code<myStruct> {
            static DDS_TypeCode * get()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member myStruct_g_tc_members[1]=
                {

                    {
                        (char *)"myLong",/* Member name */
                        {
                            0,/* Representation ID */          
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL/* Ignored */
                    }
                };

                static DDS_TypeCode myStruct_g_tc =
                {{
                        DDS_TK_STRUCT,/* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"myStruct", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        1, /* Number of members */
                        myStruct_g_tc_members, /* Members */
                        DDS_VM_NONE  /* Ignored */         
                    }}; /* Type code for myStruct*/

                if (is_initialized) {
                    return &myStruct_g_tc;
                }

                myStruct_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                is_initialized = RTI_TRUE;

                return &myStruct_g_tc;
            }
        }; // native_type_code

        const dds::core::xtypes::StructType& dynamic_type<myStruct>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(native_type_code<myStruct>::get())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<myStruct>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            rti::domain::register_type_plugin(
                participant,
                type_name,
                myStructPlugin_new,
                myStructPlugin_delete);
        }

        std::vector<char>& topic_type_support<myStruct>::to_cdr_buffer(
            std::vector<char>& buffer, const myStruct& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = myStructPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = myStructPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support<myStruct>::from_cdr_buffer(myStruct& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = myStructPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create myStruct from cdr buffer");
        }

        void topic_type_support<myStruct>::reset_sample(myStruct& sample) 
        {
            rti::topic::reset_sample(sample.myLong());
        }

        void topic_type_support<myStruct>::allocate_sample(myStruct& sample, int, int) 
        {
        }

    }
}  


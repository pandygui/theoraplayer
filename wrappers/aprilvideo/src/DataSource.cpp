/************************************************************************************
This source file is part of the Theora Video Playback Library
For latest info, see http://libtheoraplayer.googlecode.com
*************************************************************************************
Copyright (c) 2008-2014 Kresimir Spes (kspes@cateia.com)
This program is free software; you can redistribute it and/or modify it under
the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
*************************************************************************************/
#include "DataSource.h"

AprilVideoDataSource::AprilVideoDataSource(hstr filename)
{
	mFilename = filename;
	mResource.open(filename);
	
	mSize = mResource.size();
}

AprilVideoDataSource::~AprilVideoDataSource()
{
	mResource.close();
}

int AprilVideoDataSource::read(void* output, int nBytes)
{
	return mResource.read_raw(output, nBytes);
}

void AprilVideoDataSource::seek(unsigned long byte_index)
{
	mResource.seek(byte_index, hresource::START);
}

unsigned long AprilVideoDataSource::size()
{
	return mSize;
}

unsigned long AprilVideoDataSource::tell()
{
	return mResource.position();
}

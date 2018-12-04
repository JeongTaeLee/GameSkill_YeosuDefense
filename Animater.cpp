#include "DXUT.h"
#include "Animater.h"


Animater::Animater()
	: renderer(nullptr), vNowAni(nullptr), count (0), amount(0), Delay(0.f), Accrue(0.f)
{
}


Animater::~Animater()
{
}

void Animater::Add(cstr aniKey, cstr imagekey, cstr paths, int mn, int mx)
{
	vector<texture*> * ani = new vector<texture*>;

	for (int i = mn; i <= mx; ++i)
	{
		char key[256];
		sprintf(key, imagekey.c_str(), i);

		char path[256];
		sprintf(path, paths.c_str(), i);

		ani->push_back(IMAGE.AddTexture(key, path));
	}

	anis.insert(make_pair(aniKey, ani));
}

void Animater::Play(cstr aniKey)
{
	auto find = anis.find(aniKey);

	if (find == anis.end())
		return;

	bStop = false;

	sNowAni = find->first;
	vNowAni = find->second;
	renderer->SetTexture((*vNowAni)[0]);
	
	count	= 0;
	amount	= vNowAni->size() - 1;

	Accrue = 0.f;
}

void Animater::Stop(int m)
{
	bStop = true;
	renderer->SetTexture((*vNowAni)[m]);

	Accrue = 0;
}

void Animater::Start()
{
	renderer = gameObject->GC(Renderer);

}

void Animater::Release()
{
	vNowAni = nullptr;
	
	for (auto Iter : anis)
	{
		SAFE_DELETE(Iter.second);
	}
	anis.clear();
}

void Animater::Update(float Et)
{
	if (bStop)
		return;

	Accrue += Et;

	if (Delay <= Accrue)
	{
		Accrue = 0.f;
		if (count < amount)
			++count;
		else
		{
			Send("EndAnimation");
			count = 0;
		}

		renderer->SetTexture((*vNowAni)[count]);
	}
}

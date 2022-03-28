#include "framework.h"
#include "TownBG_Day.h"
#include "CD2DImage.h"

TownBG_Day::TownBG_Day()
{
}

TownBG_Day::~TownBG_Day()
{
}

TownBG_Day* TownBG_Day::Clone()
{
    return new TownBG_Day(*this);
}

void TownBG_Day::update()
{
}

void TownBG_Day::render()
{
    fPoint pos = fPoint(0, 160.f);
    fPoint scale = GetScale();
    fPoint renderpos = CCameraManager::getInst()->GetRenderPos(pos);
    renderpos = pos + (renderpos - pos) / 7;

    CRenderManager::getInst()->RenderImage(
        m_pImg,
        renderpos.x,
        renderpos.y,
        renderpos.x + scale.x,
        renderpos.y + scale.y
    );
}

void TownBG_Day::Load(wstring strKey, wstring strPath)
{
    m_pImg = CResourceManager::getInst()->LoadD2DImage(strKey, strPath);
    SetScale(fPoint(m_pImg->GetWidth() * 4.f, m_pImg->GetHeight() * 4.f));
}

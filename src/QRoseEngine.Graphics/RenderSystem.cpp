#include <QRoseEngine.Graphics/RenderSystem.hpp>

#include <QRoseEngine.Core/Components/TransformationComponent.hpp>
#include <QRoseEngine.Graphics/Components/MeshComponent.hpp>

using namespace QRose;

RenderSystem::RenderSystem(Ptr<Render> pRender, Ptr<EntitiesComponentsService> pEntitiesComponentsService)
	: render(pRender), ecs(pEntitiesComponentsService)
{
	if(pRender == nullptr)
	{
		throw std::invalid_argument("pRender == nullptr");
	}
	if(pEntitiesComponentsService == nullptr)
	{
		throw std::invalid_argument("pEntitiesComponentsService == nullptr");
	}
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::Update(double millisecondsElapsed)
{
	render->ClearView();
	render->BeginDrawing();

	Ptr<Manager<MeshComponent>> meshComponentsManager = ecs->GetManager<MeshComponent>();
	const std::vector<std::pair<Handle, MeshComponent>>& entitiesWithMeshes = meshComponentsManager->GetAllComponents();
	std::vector<std::tuple<const Handle*, const MeshComponent*, const TransformationComponent*>> toDraw;
	toDraw.reserve(entitiesWithMeshes.size());
	Ptr<Manager<TransformationComponent>> transformComponentsManager = ecs->GetManager<TransformationComponent>();
	for (auto& entityWithMesh : entitiesWithMeshes)
	{
		if (transformComponentsManager->Contains(entityWithMesh.first))
		{
			toDraw.push_back(std::make_tuple(&entityWithMesh.first, &entityWithMesh.second,
				&transformComponentsManager->GetComponent(entityWithMesh.first)));
		}
	}
	for (const auto& toDrawTuple : toDraw)
	{
		const MeshComponent& meshComponent = *std::get<1>(toDrawTuple);
		const TransformationComponent& transform = *std::get<2>(toDrawTuple);
		render->DrawMesh(meshComponent.meshId, transform.position);
	}

	render->Present();
}